
#pragma warning(disable: 4786)

#include <lxu_scene.hpp>
#include <lxidef.h>
#include <string>
#include <list>
#include <map>
#include <vector>
#include <set>

/*
 * Bring in LXsICHAN_VIDEOSTILL_FILENAME constant.
 */
#include <lxidef.h>
#include <lxu_queries.hpp>
#include <lx_value.hpp>
#include <lx_util.hpp>
#include <lxu_prefvalue.hpp>
#include <lx_deform.hpp>
#include <lx_action.hpp>
#include <lx_locator.hpp>

#include <lxu_scene.hpp>
#include <lx_deform.hpp>
#include <lxu_log.hpp>
#include <lxlog.h>

#include "cio_math.h"

#ifndef M_PI
#define M_PI = 3.14159265358979323846264338327950288;
#endif
/*
 * ----------------------------------------------------------------
 * MRZ Saver
 */

#if 0
class MRZFormat : public CLxLineFormat
{
    public:
        virtual const char *	 lf_Separator  ()		{ return " "; }
};

class MRZAnimFormat : public CLxLineFormat
{
public:
    virtual const char *	 lf_Separator  ()		{ return " "; }
};

#else

class MRZFormat : public CLxBinaryFormat
{
    public:
    MRZFormat() : CLxBinaryFormat(){}
    bool ff_Open(const char * fname){
        m_filename = std::string(fname);
        return CLxBinaryFormat::ff_Open(fname);
    }
    std::string m_filename;
};

class MRZAnimFormat : public CLxBinaryFormat
{
public:
    MRZAnimFormat() : CLxBinaryFormat(){}
    bool ff_Open(const char * fname){
        m_filename = std::string(fname);
        return CLxBinaryFormat::ff_Open(fname);
    }
    void Write(const char* str, int offset)
    {
        lf_Output(str, offset);
    }
    std::string m_filename;
};

#endif

class MRZSaver : public CLxSceneSaver, public MRZFormat
{
public:
    virtual CLxFileFormat *	 ss_Format() { return this; }

    virtual LxResult	 ss_Save      ();
    virtual void		 ss_Point     ();
    virtual void		 ss_Polygon   ();
    
    struct mzmatrix
    {
        mzmatrix(float f0, float f1, float f2, float f3,
                 float f4, float f5, float f6, float f7,
                 float f8, float f9, float f10, float f11,
                 float f12, float f13, float f14, float f15)
        {
            f[0]  = f0;  f[1]  = f1;  f[2]  = f2;  f[3]  = f3;
            f[4]  = f4;  f[5]  = f5;  f[6]  = f6;  f[7]  = f7;
            f[8]  = f8;  f[9]  = f9;  f[10] = f10; f[11] = f11;
            f[12] = f12; f[13] = f13; f[14] = f14; f[15] = f15;
        }
        mzmatrix(){}
        float f[16];
    };
    struct mzanim{
        mzmatrix mtx;
        float visible;
    };
    
    void initInfo();
    void makeMaterialsInfo();
    void makeMeshInfo();
    void writeNode_mesh(int depth, const mzmatrix& mtx);
    void writeNode_meshinst(int depth, const mzmatrix& mtx);
    void writeNode_locator(int depth, const mzmatrix& mtx);
    void writeNode_camera(int depth, const mzmatrix& mtx);
    
    bool writeNodeRec(CLxUser_Item& item, int depth);
    void writeNodes();
    void writeAnimations();
    void writeMaterials(unsigned char level);

	int getWriteNodesCountRec(CLxUser_Item& item);
	int getWriteNodesCount();


    double GetFrameRate ()
    {
        LxResult		 result(LXe_OK);
        double			 frameRate = 30;
        CLxLoc_Item		 curItem;
        bool getitem = false;
        if (GetItem (curItem))
            getitem = true;
        
        StartScan (LXsITYPE_SCENE);
        if (NextItem ()) {
            frameRate = ChanFloat (LXsICHAN_SCENE_FPS);
        }
        
        if (getitem)
            SetItem (curItem);
        
        return frameRate;
    }
    double getmaxChannelTime(const char* channame) const;
    int getMaxFrame(double fps);
    
    void gatherAnim(std::map<std::string, std::vector<mzanim> >& animkey, int maxframe);
    
    //-------------
    static LXtTagInfoDesc descInfo[];

    double m_fps;
    bool m_getpoly;
    bool m_duplicateVertex;
    std::string m_targetMat;
    
    MRZAnimFormat m_animfile;
    
    struct Param{
        Param()
        {
            memset(trans, 0, sizeof(LXtVector));
            memset(rot,   0, sizeof(LXtVector));
            scale[0] = 1.0;
            scale[1] = 1.0;
            scale[2] = 1.0;
            axis[0] = 0;
            axis[1] = 1;
            axis[2] = 2;
        }
        Param(const LXtVector* t,const LXtVector* r, const LXtVector* s, const int* a)
        {
            memcpy(trans, t, sizeof(LXtVector));
            memcpy(rot,   r, sizeof(LXtVector));
            memcpy(scale, s, sizeof(LXtVector));
            axis[0] = a[0];
            axis[1] = a[1];
            axis[2] = a[2];
        }
        LXtVector trans;
        LXtVector rot;
        LXtVector scale;
        int axis[3];
        
        class Vec3
        {
        public:
            Vec3(){}
            Vec3(double _x, double _y, double _z)
            {
                x = _x;
                y = _y;
                z = _z;
            }
            double x,y,z;
        };
        std::map<std::string,Vec3> chanvec;
    };
    
    
    std::map<std::string,unsigned int> m_tricount;
    std::map<std::string,Param> m_defparam;
    //-------------------
    class VertexFormat
    {
    public:
        VertexFormat(){}
        VertexFormat(float* pos_, float* nor_, float* uv_)
        {
            pos[0] = pos_[0];
            pos[1] = pos_[1];
            pos[2] = pos_[2];
            nor[0] = nor_[0];
            nor[1] = nor_[1];
            nor[2] = nor_[2];
            uv [0] = uv_ [0];
            uv [1] = uv_ [1];       
        }
        bool operator== (const VertexFormat& t) const
        {
            return (memcmp(this, &t, sizeof(VertexFormat)) == 0);
        }
        bool operator< (const VertexFormat& t) const
        {
            return *reinterpret_cast<const int*>(&pos[0]) < *reinterpret_cast<const int*>(&t.pos[0])
            ||     *reinterpret_cast<const int*>(&pos[1]) < *reinterpret_cast<const int*>(&t.pos[1])
            ||     *reinterpret_cast<const int*>(&pos[2]) < *reinterpret_cast<const int*>(&t.pos[2])
            ||     *reinterpret_cast<const int*>(&nor[0]) < *reinterpret_cast<const int*>(&t.nor[0])
            ||     *reinterpret_cast<const int*>(&nor[1]) < *reinterpret_cast<const int*>(&t.nor[1])
            ||     *reinterpret_cast<const int*>(&nor[2]) < *reinterpret_cast<const int*>(&t.nor[2])
            ||     *reinterpret_cast<const int*>(&uv [0]) < *reinterpret_cast<const int*>(&t.uv [0])
            ||     *reinterpret_cast<const int*>(&uv [1]) < *reinterpret_cast<const int*>(&t.uv [1]);
        }
        float pos[3];
        float nor[3];
        float uv [2];
    };
    std::map<std::string, std::map<std::string, std::vector<VertexFormat> > > m_mesh_vertex;
    
    class VertexPolygon {
    public:
        VertexPolygon(LXtPointID pointid, LXtPolygonID polygonid = 0, const std::string& matname = "")
        {
            pntid  = pointid;
            polyid = polygonid;
            mat = matname;
        }
        bool operator<(const VertexPolygon& t) const
        {
            return pntid < t.pntid;
        }
        bool operator==(const VertexPolygon& t) const
        {
            return pntid == t.pntid;
        }
        LXtPointID pntid;
        LXtPolygonID polyid;
        std::string mat;
    };
    std::multiset<VertexPolygon> m_vertexpoly;
    
    class PolygonVertex {
    public:
        PolygonVertex(){}
        PolygonVertex(LXtPolygonID polygonid, LXtPointID pointid)
        {
            pntid    = pointid;
            polyid   = polygonid;
        }
        bool operator<(const PolygonVertex& t) const
        {
            return polyid < t.polyid
                || (!(t.polyid < polyid) && pntid < t.pntid);
        }
        LXtPointID pntid;
        LXtPolygonID polyid;
    };
    class MaterialInfo
    {
    public:
        MaterialInfo(){
            color[0] = 0.8f;
            color[1] = 0.8f;
            color[2] = 0.8f;
            color[3] = 1.0f;
        }
        float color[4];
        std::string tex;
    };
    std::map<std::string, std::map<std::string, std::map<PolygonVertex, unsigned int> > > m_mesh_polyvertex;
    std::map<std::string, std::map<std::string, unsigned int> > m_mesh_trinum;
    std::map<std::string, unsigned int> m_mattable;
    std::map<std::string, MaterialInfo> m_matinfo;
};

LXtTagInfoDesc	 MRZSaver::descInfo[] = {
    { LXsSAV_OUTCLASS,	LXa_SCENE	},
    { LXsSAV_DOSTYPE,	"MRZ"		},
    { LXsSRV_USERNAME,	"MRZ format"},
    { 0 }
};


void MRZSaver::makeMaterialsInfo()
{
    std::map<std::string, unsigned int>::const_iterator it,eit = m_mattable.end();
    for (it = m_mattable.begin(); it != eit; ++it)
    {
        const char* mask = it->first.c_str();
        if (!ScanMask (mask)) {
            m_mattable[mask] = 0x1;
            continue;
        }

        MaterialInfo mat;
        while (NextLayer ())
        {
            if (ItemIsA (LXsITYPE_ADVANCEDMATERIAL))
            {
                std::string name = ItemName();
                float rgb[3];
                rgb[0] = ChanFloat (LXsICHAN_ADVANCEDMATERIAL_DIFFCOL".R");
                rgb[1] = ChanFloat (LXsICHAN_ADVANCEDMATERIAL_DIFFCOL".G");
                rgb[2] = ChanFloat (LXsICHAN_ADVANCEDMATERIAL_DIFFCOL".B");
                printf("name=%s - RGB(%f,%f,%f)\n", name.c_str(), rgb[0], rgb[1], rgb[2]);

                mat.color[0] = rgb[0];
                mat.color[1] = rgb[1];
                mat.color[2] = rgb[2];
            }
            else if (ItemIsA (LXsITYPE_IMAGEMAP))
            {
                std::string fx = LayerEffect ();
                if (fx == LXs_FX_DIFFCOLOR)
                {
                    if (TxtrImage())
                    {
                        std::string fname = ChanString (LXsICHAN_VIDEOSTILL_FILENAME);
                        printf("fx=%s texname=%s\n", fx.c_str(), fname.c_str());
                        mat.tex = fname;
                    }
                }
            }
        }
        printf("\n");
        m_matinfo[it->first] = mat;
    }
}

void MRZSaver::makeMeshInfo()
{
    m_vertexpoly.clear();
    m_tricount.clear();
    
    m_getpoly = true;
    WritePolys();
    m_getpoly = false;
    m_duplicateVertex = true;
    std::map<std::string, unsigned int>::const_iterator it,eit = m_mattable.end();
    for (it = m_mattable.begin(); it != eit; ++it) {
        m_targetMat = it->first;
        WritePoints();
    }
    m_duplicateVertex = false;

    for (it = m_mattable.begin(); it != eit; ++it) {
        const std::string meshname = std::string(ItemName());
        m_mesh_trinum[meshname][it->first] = m_tricount[it->first];
        unsigned int numv = m_mesh_vertex[meshname][it->first].size();
        unsigned int plyid = m_mesh_polyvertex[meshname][it->first].size();
        //printf("name = %s type = %s\n",ItemName(), ItemType());
        printf("name = %s mat = %s fianl vertex num = %d  polyid = %d tri num = %d\n", ItemName(), it->first.c_str(), numv, plyid, m_tricount[it->first]);
    }
    
}

void MRZSaver::initInfo()
{
    m_tricount.clear();;
    m_mattable.clear();
    m_vertexpoly.clear();
    m_mesh_vertex.clear();
    m_mesh_polyvertex.clear();
    m_mesh_trinum.clear();
    m_defparam.clear();
}


void MRZSaver::writeNode_mesh(int depth, const mzmatrix& mtx)
{
    const std::string meshname = std::string(ItemName());
    
    // Transform
    unsigned char level = depth;
    lf_Output("TSF",-1);
    lf_Output(level);
    lf_Output(meshname.c_str());
    for (int i = 0; i < 16; ++i){
        const float f = mtx.f[i];
        lf_Output(f);
    }
	++level;
    
    std::map<std::string, MaterialInfo>::const_iterator it,eit = m_matinfo.end();
    for (it = m_matinfo.begin(); it != eit; ++it) {
        const std::string& matname = it->first;
        if (m_mesh_vertex[meshname].find(matname) == m_mesh_vertex[meshname].end())
            continue;
        unsigned int numv = m_mesh_vertex[meshname][matname].size();
        if (!numv)
            continue;
        unsigned int trinum =  m_mesh_trinum[meshname][matname];
        
        // mesh
        lf_Output("MSH",-1);
        lf_Output(level);
        lf_Output((meshname + std::string("_geo_") + matname).c_str());
	
        lf_Output(numv); // vertex num
        lf_Output(trinum * 3); // idx num
	
        // mat id
        //lf_Output("mat_phong");
        lf_Output(matname.c_str());
        printf("writeNode_Mesh : mesh = %s mat = %s\n", meshname.c_str(), matname.c_str());
	
        for (unsigned int i = 0; i < numv; i++)
        {
            const unsigned int col = 0xFFFFFFFF;
            lf_Output(m_mesh_vertex[meshname][matname][i].pos[0]);
            lf_Output(m_mesh_vertex[meshname][matname][i].pos[1]);
            lf_Output(m_mesh_vertex[meshname][matname][i].pos[2]);
            lf_Output(col);
            lf_Output(m_mesh_vertex[meshname][matname][i].nor[0]);
            lf_Output(m_mesh_vertex[meshname][matname][i].nor[1]);
            lf_Output(m_mesh_vertex[meshname][matname][i].nor[2]);
            lf_Output(m_mesh_vertex[meshname][matname][i].uv [0]);
            lf_Output(m_mesh_vertex[meshname][matname][i].uv [1]);
        }
        
        m_targetMat = matname;
        WritePolys();
    }
}



void MRZSaver::writeNode_meshinst(int depth, const mzmatrix& mtx)
{
    const std::string meshname = std::string(ItemName());
    
    // Transform
    unsigned char level = depth;
    lf_Output("TSF",-1);
    lf_Output(level);
    lf_Output(meshname.c_str());
    for (int i = 0; i < 16; ++i){
        const float f = mtx.f[i];
        lf_Output(f);
    }
	++level;
    
    std::string instmeshname = "mesh";
    /* get meshinst info */
    CLxUser_SceneService	 service;
    CLxUser_Item		 meshInstItem;
    CLxUser_Item		 srcMeshItem;
    ILxItem1ID		 iMesh;
    if (GetItem (meshInstItem)) {
        if (LXx_OK (service.GetMeshInstSourceItem ((ILxUnknownID)meshInstItem, (void**)&iMesh))) {
            SetItem ((ILxUnknownID)iMesh);
            instmeshname = std::string(ItemName());
        }
        SetItem (meshInstItem); // restore
    }

    lf_Output("INS",-1);
    lf_Output(level);
    lf_Output((instmeshname).c_str());
}

void MRZSaver::writeNode_locator(int depth, const mzmatrix& mtx)
{
    // Transform
    const std::string meshname = std::string(ItemName());
    unsigned char level = depth;
    lf_Output("TSF",-1);
    lf_Output(level);
    lf_Output(meshname.c_str());
    for (int i = 0; i < 16; ++i){
        const float f = mtx.f[i];
        lf_Output(f);
    }
}

void MRZSaver::writeNode_camera(int depth, const mzmatrix& mtx)
{
    const std::string meshname = std::string(ItemName());
    unsigned char level = depth;
    lf_Output("CAM",-1);
    lf_Output(level);
    lf_Output((meshname).c_str());
    const double ax = ChanFloat(LXsICHAN_CAMERA_APERTUREX);
    const double fl = ChanFloat(LXsICHAN_CAMERA_FOCALLEN);
    float holfov = static_cast<float>(atan2(ax*.5,fl)*180.0/M_PI*2.0);
    lf_Output(holfov);
}

enum {
    ROTATION_ORDER_XYZ,
    ROTATION_ORDER_XZY,
    ROTATION_ORDER_YXZ,
    ROTATION_ORDER_YZX,
    ROTATION_ORDER_ZXY,
    ROTATION_ORDER_ZYX
};

static void buildAxisOrder (int	rotationOrder, int	axis[3])
{
    switch (rotationOrder) {
        case ROTATION_ORDER_XZY:
            axis[0] = 0;
            axis[1] = 2;
            axis[2] = 1;
            break;
            
        case ROTATION_ORDER_YXZ:
            axis[0] = 1;
            axis[1] = 0;
            axis[2] = 2;
            break;
            
        case ROTATION_ORDER_YZX:
            axis[0] = 1;
            axis[1] = 2;
            axis[2] = 0;
            break;
            
        case ROTATION_ORDER_ZXY:
            axis[0] = 2;
            axis[1] = 0;
            axis[2] = 1;
            break;
            
        case ROTATION_ORDER_ZYX:
            axis[0] = 2;
            axis[1] = 1;
            axis[2] = 0;
            break;
            
        case ROTATION_ORDER_XYZ:
        default:
            axis[0] = 0;
            axis[1] = 1;
            axis[2] = 2;
            break;
    }
}

bool MRZSaver::writeNodeRec(CLxUser_Item& item, int depth)
{
    SetItem(item);
    if (   !ItemIsA (LXsITYPE_MESH)
        && !ItemIsA (LXsITYPE_CAMERA)
        && !ItemIsA (LXsITYPE_GROUPLOCATOR)
        && !ItemIsA (LXsITYPE_LOCATOR)
        && !ItemIsA (LXsITYPE_MESHINST)
        && !ItemIsA (LXsITYPE_LIGHT)
        && !ItemIsA (LXsITYPE_TEXTURELOC)
        ){
        return false;
    }

    CLxUser_Scene      scene(SceneObject ());
    CLxUser_SceneGraph sceneGraph;
    CLxUser_ItemGraph  itemGraph;
    scene.GetGraph (LXsGRAPH_XFRMCORE, sceneGraph);
    itemGraph.set (sceneGraph);
    
    for (int d = 0; d < depth; ++d)
        printf("-");
    printf(" item name = %s\n", ItemName());
    std::string itemN = std::string(ItemName());
    
    using namespace cio::math;
    Matrix4		m;
    Matrix4Identity (m);
    LXtVector def_trans = {0,0,0};
    LXtVector def_rot = {0,0,0};
    int def_axis[3] = {0,1,2};
    LXtVector def_scale = {1,1,1};
    Param param;
    /*
     * For the matrix case, we need to reverse iterate
     * over the transform graph.
     */
    unsigned transformCount = itemGraph.Reverse (item);
    for (unsigned transformIndex = 0; transformIndex < transformCount; ++transformIndex) {
        CLxUser_Item transform;
        if (itemGraph.Reverse (item, transformIndex, transform)) {
            SetItem (transform);
            std::string chanName(ItemName ());
            
            const char *xformType = ItemType ();
            if (std::string(xformType) == std::string(LXsITYPE_SCALE)) {
                LXtVector	scale;
                ChanXform (LXsICHAN_SCALE_SCL, scale);
                memcpy(def_scale,scale,sizeof(LXtVector));
                LXtMatrix4 sm;
                Matrix4CreateScale (sm, scale);
                Matrix4Compose (m, sm);
                param.chanvec.insert(std::make_pair(chanName,Param::Vec3(scale[0],scale[1],scale[2])));
            }
            else if (std::string(xformType) == std::string(LXsITYPE_ROTATION)) {
                LXtVector rotate;
                ChanXform (LXsICHAN_ROTATION_ROT, rotate);
                memcpy(def_rot,rotate,sizeof(LXtVector));
                /*
                 * Take rotation order
                 * into account.
                 */
                int axis[3];
                buildAxisOrder (ChanInt (LXsICHAN_ROTATION_ORDER), axis);
                memcpy(def_axis,axis,sizeof(int)*3);
                
                LXtMatrix4 rm;
                Matrix4CreateRotation (rm, rotate[axis[0]], axis[0]);
                Matrix4Compose (m, rm);
                Matrix4CreateRotation (rm, rotate[axis[1]], axis[1]);
                Matrix4Compose (m, rm);
                Matrix4CreateRotation (rm, rotate[axis[2]], axis[2]);
                Matrix4Compose (m, rm);
                param.chanvec.insert(std::make_pair(chanName,Param::Vec3(rotate[0],rotate[1],rotate[2])));
            }
            else if (std::string(xformType) == std::string(LXsITYPE_TRANSLATION)) {
                LXtVector	translate;
                ChanXform (LXsICHAN_TRANSLATION_POS, translate);
                memcpy(def_trans,translate,sizeof(LXtVector));
                LXtMatrix4 tm;
                Matrix4CreateTranslation (tm, translate);
                Matrix4Compose (m, tm);
                param.chanvec.insert(std::make_pair(chanName,Param::Vec3(translate[0],translate[1],translate[2])));
            }
            else if (std::string(xformType) == std::string(LXsITYPE_TRANSFORM)) {
                LXtVector	translate = {0, 0, 0};
                
                /*
                 * Walk the local graph and find the translate item for
                 * which this transform is the inverse.
                 */
                CLxUser_Scene		 scene(SceneObject ());
                CLxUser_SceneGraph	 sceneGraph;
                scene.GetGraph (LXsGRAPH_XFRMLOCAL, sceneGraph);
                CLxUser_ItemGraph localGraph;
                localGraph.set (sceneGraph);
                CLxUser_Item localTransform;
                if (localGraph.Reverse (transform, 0, localTransform)) {
                    /*
                     * Fetch the translation vector and negate it.
                     */
                    SetItem (localTransform);
                    if (ItemType () == std::string(LXsITYPE_TRANSLATION)) {
                        ChanXform (LXsICHAN_TRANSLATION_POS, translate);
                        translate[0] = -translate[0];
                        translate[1] = -translate[1];
                        translate[2] = -translate[2];
                        
                        /*
                         * And bake it in...
                         */
                        LXtMatrix4 tm;
                        Matrix4CreateTranslation (tm, translate);
                        Matrix4Compose (m, tm);
                    }
                }
            }
            
            /*
             * More diagnostic goodies.
             */
            LXtItemType itemType = transform.Type ();
        }
    }
    
    memcpy(&param.trans, def_trans, sizeof(LXtVector));
    memcpy(&param.rot, def_rot, sizeof(LXtVector));
    memcpy(&param.scale, def_scale, sizeof(LXtVector));
    m_defparam[itemN] = param;
                                                

    
    SetItem(item); // reset item.
    
    mzmatrix mtx(m[0][0],m[0][1],m[0][2],m[0][3],
                 m[1][0],m[1][1],m[1][2],m[1][3],
                 m[2][0],m[2][1],m[2][2],m[2][3],
                 m[3][0],m[3][1],m[3][2],m[3][3]);
    if (ItemIsA (LXsITYPE_MESHINST)) {
        writeNode_meshinst(depth, mtx);
    }else if (ItemIsA (LXsITYPE_MESH)) {
        writeNode_mesh(depth, mtx);
    }else if (ItemIsA (LXsITYPE_CAMERA)){
        writeNode_locator(depth, mtx);
        writeNode_camera(depth+1,mtx);
    } else if (ItemIsA (LXsITYPE_LOCATOR) || ItemIsA(LXsITYPE_GROUPLOCATOR)) {
        writeNode_locator(depth, mtx);
    }
    
    SetItem(item); // reset item.
    
    // -- Recursive Sub node. --
    unsigned int cnt = 0;
    if (item.SubCount(&cnt) != LXe_OK)
        return false;
    for (unsigned int i = 0; i < cnt; ++i){
        LXtObjectID	sub = NULL;
        if (item.SubByIndex(i, reinterpret_cast<void**>(&sub)) != LXe_OK)
            continue;
        
        CLxUser_Item subitem;
        subitem.set(sub);
        
        writeNodeRec(subitem, depth + 1);
    }
    return true;
}
void MRZSaver::writeNodes()
{
    StartScan();
    while (NextItem()) {
        CLxLoc_Item item;
        if (GetItem(item)) {
            LXtObjectID	parent = NULL;
            if (item.Parent (reinterpret_cast<void**>(&parent)) == LXe_OK) {
                /*
                 * Skip non-root nodes.
                 */
                lx::ObjRelease (parent);
                continue;
            }
            
            CLxUser_Item ritem(item);
            writeNodeRec(ritem,1);
            SetItem(item);
        }
    }
}

int MRZSaver::getWriteNodesCountRec(CLxUser_Item& item)
{
	int num = 0;
	SetItem(item);
	
    if (!ItemIsA (LXsITYPE_MESH)
    &&  !ItemIsA (LXsITYPE_CAMERA)
    &&  !ItemIsA (LXsITYPE_GROUPLOCATOR)
    &&  !ItemIsA (LXsITYPE_LOCATOR)
    &&  !ItemIsA (LXsITYPE_MESHINST)
    &&  !ItemIsA (LXsITYPE_LIGHT)
    &&  !ItemIsA (LXsITYPE_TEXTURELOC)
    ){
        return 0;
    }
	
	++num;
	if (ItemIsA(LXsITYPE_MESHINST)
    ||  ItemIsA(LXsITYPE_CAMERA)) // will be 2 nodes
        ++num;
    
	// -- Recursive Sub node. --
    unsigned int cnt = 0;
    if (item.SubCount(&cnt) != LXe_OK)
        return num;
    for (unsigned int i = 0; i < cnt; ++i){
        LXtObjectID	sub = NULL;
        if (item.SubByIndex(i, reinterpret_cast<void**>(&sub)) != LXe_OK)
            continue;
        
        CLxUser_Item subitem;
        subitem.set(sub);
        
        num += getWriteNodesCountRec(subitem);
    }
	return num;
}

int MRZSaver::getWriteNodesCount()
{
	int num = 0;
	StartScan();
    while (NextItem()) {
        CLxLoc_Item item;
        if (GetItem(item)) {
            LXtObjectID	parent = NULL;
            if (item.Parent (reinterpret_cast<void**>(&parent)) == LXe_OK) {
                /*
                 * Skip non-root nodes.
                 */
                lx::ObjRelease (parent);
                continue;
            }
            
            CLxUser_Item ritem(item);
            num += getWriteNodesCountRec(ritem);
            SetItem(item);
        }
    }
	return num;
}

double MRZSaver::getmaxChannelTime(const char* channame) const
{
    double tm = 0;
    CLxUser_Keyframe key;
    CLxUser_Envelope envelope;
    if (ChanEnvelope (channame, envelope)){
        envelope.GetKeyframe(&key);
        key.GetTime(&tm);
        while (key.Next() == LXe_OK)
            key.GetTime(&tm);
    }
    return tm;
}


namespace {
    static const std::string translationChannelXname = std::string(LXsICHAN_TRANSLATION_POS) + ".X";
    static const std::string translationChannelYname = std::string(LXsICHAN_TRANSLATION_POS) + ".Y";
    static const std::string translationChannelZname = std::string(LXsICHAN_TRANSLATION_POS) + ".Z";
    static const std::string rotationChannelXname = std::string(LXsICHAN_ROTATION_ROT) + ".X";
    static const std::string rotationChannelYname = std::string(LXsICHAN_ROTATION_ROT) + ".Y";
    static const std::string rotationChannelZname = std::string(LXsICHAN_ROTATION_ROT) + ".Z";
    static const std::string scaleChannelXname = std::string(LXsICHAN_SCALE_SCL) + ".X";
    static const std::string scaleChannelYname = std::string(LXsICHAN_SCALE_SCL) + ".Y";
    static const std::string scaleChannelZname = std::string(LXsICHAN_SCALE_SCL) + ".Z";
}

int MRZSaver::getMaxFrame(double fps)
{
    double maxtm = 0;
    StartScan ();
    while (NextItem ()) {
        if (ItemIsA (LXsITYPE_CAMERA) ||
            ItemIsA (LXsITYPE_MESH) ||
            ItemIsA (LXsITYPE_MESHINST) ||
            ItemIsA (LXsITYPE_GROUPLOCATOR) ||
            ItemIsA (LXsITYPE_LIGHT) ||
            ItemIsA (LXsITYPE_LOCATOR) ||
            ItemIsA (LXsITYPE_TEXTURELOC)) {
            
            std::string itemName = ItemName ();
            std::string	itemType = ItemType ();
            CLxLoc_Item selectedItem;
            if (GetItem (selectedItem)) {
                if (HasXformItem (LXiXFRM_POSITION) && XformItem (LXiXFRM_POSITION)) {
                    double tm = 0;
                    tm = getmaxChannelTime(translationChannelXname.c_str());
                    if (maxtm < tm)
                        maxtm = tm;
                    tm = getmaxChannelTime(translationChannelYname.c_str());
                    if (maxtm < tm)
                        maxtm = tm;
                    tm = getmaxChannelTime(translationChannelZname.c_str());
                    if (maxtm < tm)
                        maxtm = tm;
                }
                SetItem (selectedItem);
                
                if (HasXformItem (LXiXFRM_ROTATION) && XformItem (LXiXFRM_ROTATION)) {
                    double tm = 0;
                    tm = getmaxChannelTime(rotationChannelXname.c_str());
                    if (maxtm < tm)
                        maxtm = tm;
                    tm = getmaxChannelTime(rotationChannelYname.c_str());
                    if (maxtm < tm)
                        maxtm = tm;
                    tm = getmaxChannelTime(rotationChannelZname.c_str());
                    if (maxtm < tm)
                        maxtm = tm;
                }
                SetItem (selectedItem);
                
                if (HasXformItem (LXiXFRM_SCALE) && XformItem (LXiXFRM_SCALE)) {
                    double tm = 0;
                    tm = getmaxChannelTime(scaleChannelXname.c_str());
                    if (maxtm < tm)
                        maxtm = tm;
                    tm = getmaxChannelTime(scaleChannelYname.c_str());
                    if (maxtm < tm)
                        maxtm = tm;
                    tm = getmaxChannelTime(scaleChannelZname.c_str());
                    if (maxtm < tm)
                        maxtm = tm;
                }
                SetItem (selectedItem);
                double tm = getmaxChannelTime(LXsICHAN_UISTATE_VISIBLE);
                if (maxtm < tm)
                    maxtm = tm;
                SetItem (selectedItem);
            }
        }
    }
    return maxtm * fps;
}

void MRZSaver::gatherAnim(std::map<std::string, std::vector<mzanim> >& animkey, int maxframe)
{
    StartScan ();
    while (NextItem ()) {
        if (ItemIsA (LXsITYPE_CAMERA) ||
            ItemIsA (LXsITYPE_MESH) ||
            ItemIsA (LXsITYPE_MESHINST) ||
            ItemIsA (LXsITYPE_GROUPLOCATOR) ||
            ItemIsA (LXsITYPE_LIGHT) ||
            ItemIsA (LXsITYPE_LOCATOR) ||
            ItemIsA (LXsITYPE_TEXTURELOC)) {
            
            std::vector<mzanim> keys;
            std::string itemName = ItemName ();
            std::string	itemType = ItemType ();
            printf("name = %s type = %s\n", itemName.c_str(), itemType.c_str());
            CLxLoc_Item selectedItem;
            if (GetItem (selectedItem)) {
                double tm = 0;
                if (HasXformItem (LXiXFRM_POSITION) && XformItem (LXiXFRM_POSITION)) {
                    tm = cio::math::Max(tm, getmaxChannelTime(translationChannelXname.c_str()));
                    tm = cio::math::Max(tm, getmaxChannelTime(translationChannelYname.c_str()));
                    tm = cio::math::Max(tm, getmaxChannelTime(translationChannelZname.c_str()));
                }
                SetItem (selectedItem);
                if (HasXformItem (LXiXFRM_ROTATION) && XformItem (LXiXFRM_ROTATION)) {
                    tm = cio::math::Max(tm, getmaxChannelTime(rotationChannelXname.c_str()));
                    tm = cio::math::Max(tm, getmaxChannelTime(rotationChannelYname.c_str()));
                    tm = cio::math::Max(tm, getmaxChannelTime(rotationChannelZname.c_str()));
                }
                SetItem (selectedItem);
                if (HasXformItem (LXiXFRM_SCALE) && XformItem (LXiXFRM_SCALE)) {
                    tm = cio::math::Max(tm, getmaxChannelTime(scaleChannelXname.c_str()));
                    tm = cio::math::Max(tm, getmaxChannelTime(scaleChannelYname.c_str()));
                    tm = cio::math::Max(tm, getmaxChannelTime(scaleChannelZname.c_str()));
                }
                SetItem (selectedItem);
                tm = cio::math::Max(tm, getmaxChannelTime(LXsICHAN_UISTATE_VISIBLE));
                SetItem (selectedItem);
                
                if (ItemIsA(LXsITYPE_MESHINST)){
                    // Check origianl mesh animation
                    /* get meshinst info */
                    CLxUser_SceneService	 service;
                    CLxUser_Item		 meshInstItem;
                    CLxUser_Item		 srcMeshItem;
                    ILxItem1ID		 iMesh;
                    if (GetItem (meshInstItem)
                    && LXx_OK (service.GetMeshInstSourceItem ((ILxUnknownID)meshInstItem, (void**)&iMesh))){
                        SetItem ((ILxUnknownID)iMesh);
                        std::string itemName = ItemName ();
                        std::string	itemType = ItemType ();
                        //printf("INSTANCE-> name = %s type = %s\n", itemName.c_str(), itemType.c_str());

                        if (HasXformItem (LXiXFRM_POSITION) && XformItem (LXiXFRM_POSITION)) {
                            tm = cio::math::Max(tm, getmaxChannelTime(translationChannelXname.c_str()));
                            tm = cio::math::Max(tm, getmaxChannelTime(translationChannelYname.c_str()));
                            tm = cio::math::Max(tm, getmaxChannelTime(translationChannelZname.c_str()));
                        }
                        SetItem ((ILxUnknownID)iMesh);
                        if (HasXformItem (LXiXFRM_ROTATION) && XformItem (LXiXFRM_ROTATION)) {
                            tm = cio::math::Max(tm, getmaxChannelTime(rotationChannelXname.c_str()));
                            tm = cio::math::Max(tm, getmaxChannelTime(rotationChannelYname.c_str()));
                            tm = cio::math::Max(tm, getmaxChannelTime(rotationChannelZname.c_str()));
                        }
                        SetItem ((ILxUnknownID)iMesh);
                        if (HasXformItem (LXiXFRM_SCALE) && XformItem (LXiXFRM_SCALE)) {
                            tm = cio::math::Max(tm, getmaxChannelTime(scaleChannelXname.c_str()));
                            tm = cio::math::Max(tm, getmaxChannelTime(scaleChannelYname.c_str()));
                            tm = cio::math::Max(tm, getmaxChannelTime(scaleChannelZname.c_str()));
                        }
                        SetItem ((ILxUnknownID)iMesh);
                        tm = cio::math::Max(tm, getmaxChannelTime(LXsICHAN_UISTATE_VISIBLE));
                        SetItem (selectedItem);
                    }
                }

                if (tm == 0)
                    continue;
                
                /*unsigned int count = 0;
                selectedItem.ChannelCount(&count);
                for (unsigned int x = 0; x < count; ++x){
                    const char* name;
                    selectedItem.ChannelName(x,&name);
                    printf("chan name = %s\n",name);
                }*/
                //selectedItem.SubCount(&count);
                int fps = 24;
                for (int f = 0; f < maxframe; ++f)
                {
                    using namespace cio::math;
                    Param p = m_defparam[itemName];
                    
                    const double time = f / m_fps;//static_cast<double>(fps);
                    //printf("Time = %lf\n",time);
                    LxResult	result(LXe_OK);
                    CLxUser_Scene      scene(SceneObject ());
                    CLxUser_SceneGraph sceneGraph;
                    CLxUser_ItemGraph  itemGraph;
                    scene.GetGraph (LXsGRAPH_XFRMCORE, sceneGraph);
                    itemGraph.set (sceneGraph);

                    Matrix4	m;
                    Matrix4Identity (m);
                    unsigned transformCount = itemGraph.Reverse (selectedItem);
                    for (unsigned transformIndex = 0; transformIndex < transformCount; ++transformIndex) {
                        CLxUser_Item transform;
                        if (itemGraph.Reverse (selectedItem, transformIndex, transform)) {
                            SetItem (transform);
                            std::string transformName(ItemName ());
                            //printf("  chanName = %s : ",transformName.c_str());
                            const char *xformType = ItemType ();
                            Vector3	vec = {0,0,0};
                            vec[0] = p.chanvec[transformName].x;
                            vec[1] = p.chanvec[transformName].y;
                            vec[2] = p.chanvec[transformName].z;

                            ILxItem1ID srctransID;
                            CLxUser_Envelope	envelope;
                            if (std::string(xformType) == std::string(LXsITYPE_SCALE)) {
                                if (LXx_OK(transform.Source((void**)&srctransID))){
                                    CLxUser_Item srcobj((ILxUnknownID)srctransID);
                                    SetItem(srcobj);
                                    if (ChanEnvelope (scaleChannelXname.c_str (), envelope))
                                        vec[0] = envelope.Value(time);
                                    if (ChanEnvelope (scaleChannelYname.c_str (), envelope))
                                        vec[1] = envelope.Value(time);
                                    if (ChanEnvelope (scaleChannelZname.c_str (), envelope))
                                        vec[2] = envelope.Value(time);
                                    SetItem(transform);
                                }
                                if (ChanEnvelope (scaleChannelXname.c_str (), envelope))
                                    vec[0] = envelope.Value(time);
                                if (ChanEnvelope (scaleChannelYname.c_str (), envelope))
                                    vec[1] = envelope.Value(time);
                                if (ChanEnvelope (scaleChannelZname.c_str (), envelope))
                                    vec[2] = envelope.Value(time);
                                //printf("Scale(%f,%f,%f)\n",vec[0],vec[1],vec[2]);
                                LXtMatrix4 sm;
                                Matrix4CreateScale (sm, vec);
                                Matrix4Compose (m, sm);
                            }
                            else if (std::string(xformType) == std::string(LXsITYPE_ROTATION)) {
                                if (LXx_OK(transform.Source((void**)&srctransID))){
                                    CLxUser_Item srcobj((ILxUnknownID)srctransID);
                                    SetItem(srcobj);
                                    if (ChanEnvelope (rotationChannelXname.c_str (), envelope))
                                        vec[0] = envelope.Value(time);
                                    if (ChanEnvelope (rotationChannelYname.c_str (), envelope))
                                        vec[1] = envelope.Value(time);
                                    if (ChanEnvelope (rotationChannelZname.c_str (), envelope))
                                        vec[2] = envelope.Value(time);
                                    SetItem(transform);
                                }
                                if (ChanEnvelope (rotationChannelXname.c_str (), envelope))
                                    vec[0] = envelope.Value(time);
                                if (ChanEnvelope (rotationChannelYname.c_str (), envelope))
                                    vec[1] = envelope.Value(time);
                                if (ChanEnvelope (rotationChannelZname.c_str (), envelope))
                                    vec[2] = envelope.Value(time);
                                int axis[3];
                                buildAxisOrder (ChanInt (LXsICHAN_ROTATION_ORDER), axis);
                                
                                //printf("Rot  (%f,%f,%f)\n",vec[0],vec[1],vec[2]);
                                LXtMatrix4 rm;
                                Matrix4CreateRotation (rm, vec[axis[0]], axis[0]);
                                Matrix4Compose (m, rm);
                                Matrix4CreateRotation (rm, vec[axis[1]], axis[1]);
                                Matrix4Compose (m, rm);
                                Matrix4CreateRotation (rm, vec[axis[2]], axis[2]);
                                Matrix4Compose (m, rm);
                            }
                            else if (std::string(xformType) == std::string(LXsITYPE_TRANSLATION)) {
                                if (LXx_OK(transform.Source((void**)&srctransID))){
                                    CLxUser_Item srcobj((ILxUnknownID)srctransID);
                                    SetItem(srcobj);
                                    if (ChanEnvelope (translationChannelXname.c_str (), envelope))
                                        vec[0] = envelope.Value(time);
                                    if (ChanEnvelope (translationChannelYname.c_str (), envelope))
                                        vec[1] = envelope.Value(time);
                                    if (ChanEnvelope (translationChannelZname.c_str (), envelope))
                                        vec[2] = envelope.Value(time);
                                    SetItem(transform);
                                }
                                if (ChanEnvelope (translationChannelXname.c_str (), envelope))
                                    vec[0] = envelope.Value(time);
                                if (ChanEnvelope (translationChannelYname.c_str (), envelope))
                                    vec[1] = envelope.Value(time);
                                if (ChanEnvelope (translationChannelZname.c_str (), envelope))
                                    vec[2] = envelope.Value(time);
                                //printf("Trans(%f,%f,%f)\n",vec[0],vec[1],vec[2]);
                                LXtMatrix4 tm;
                                Matrix4CreateTranslation (tm, vec);
                                Matrix4Compose (m, tm);
                            }
                        }
                    }
                    
                    mzmatrix mtx(m[0][0],m[0][1],m[0][2],m[0][3],
                                 m[1][0],m[1][1],m[1][2],m[1][3],
                                 m[2][0],m[2][1],m[2][2],m[2][3],
                                 m[3][0],m[3][1],m[3][2],m[3][3]);
                    
                    SetItem(selectedItem);
                    CLxUser_Envelope	envelope;
                    float vis = 1.0;
                    if (ItemIsA(LXsITYPE_CAMERA))
                    {
                        // FOV
                        double ax = ChanFloat(LXsICHAN_CAMERA_APERTUREX);
                        if (ChanEnvelope(LXsICHAN_CAMERA_FOCALLEN, envelope)) {
                            double fl = envelope.Value(time);
                            double fovx = atan2(ax*.5,fl)*180.0/M_PI*2.0;
                            vis = static_cast<float>(fovx);
                        } else {
                            vis = 60.0f;
                        }
                    } else {
                        if (ChanEnvelope(LXsICHAN_UISTATE_VISIBLE, envelope)) {
                            vis = envelope.IntValue(time);
                            if (vis < 2)
                                vis = 1.0;
                            else
                                vis = 0.0;
                        }
                    }
                    mzanim key;
                    key.mtx = mtx;
                    key.visible = vis;
                    keys.push_back(key);
                }
            }
            animkey[itemName] = keys;
        }
    }
}

void MRZSaver::writeAnimations()
{
    std::map<std::string, std::vector<mzanim> > animkey;

    int maxframe = getMaxFrame(m_fps);
    
    gatherAnim(animkey, maxframe);
    
    std::string animfilename = m_filename;
    size_t p = animfilename.find(".");
    if (p != std::string::npos){
        animfilename.erase(p);
    }
    animfilename += "_mrz.anim";
    m_animfile.ff_Open(animfilename.c_str());
    m_animfile.lf_Output("ANM",-1);
    unsigned char ver = 1;
    m_animfile.lf_Output(ver);

    unsigned int fps = static_cast<unsigned int>(m_fps);
    m_animfile.lf_Output(fps);
    unsigned int nodenum = animkey.size();
    m_animfile.lf_Output(nodenum);
    std::map<std::string, std::vector<mzanim> >::iterator it,eit = animkey.end();
    for (it = animkey.begin(); it != eit; ++it)
    {
        const char* name = it->first.c_str();
        m_animfile.lf_Output(name);
        unsigned int keynum = static_cast<unsigned int>(it->second.size());
        m_animfile.lf_Output(keynum);
        for (unsigned k = 0; k < keynum; ++k)
        {
            for (int m = 0; m < 16; ++m)
                m_animfile.lf_Output(it->second[k].mtx.f[m]);
            m_animfile.lf_Output(it->second[k].visible);
        }
    }
    m_animfile.ff_Cleanup();
}

void MRZSaver::writeMaterials(unsigned char level)
{
    std::map<std::string, MaterialInfo>::const_iterator it,eit = m_matinfo.end();
    for (it = m_matinfo.begin(); it != eit; ++it)
    {
        lf_Output("MAT",-1);
        lf_Output(level);
        lf_Output(it->first.c_str());
        printf("writeMaterial -> %s\n",it->first.c_str());
        int vec4num = 1;
        lf_Output(vec4num);
        float col_r = it->second.color[0];
        float col_g = it->second.color[1];
        float col_b = it->second.color[2];
        float col_a = it->second.color[3];
        lf_Output("color");
        lf_Output(col_r);
        lf_Output(col_g);
        lf_Output(col_b);
        lf_Output(col_a);
        int matrixnum = 0;
        lf_Output(matrixnum);
        int strnum = 0;
        if (it->second.tex != std::string(""))
            strnum = 1;
        lf_Output(strnum);
        if (strnum){
            std::string texfname = it->second.tex;
            size_t p = texfname.rfind("/");
            if (p != std::string::npos){
                texfname.erase(texfname.begin(), texfname.begin()+p+1);
            }
            lf_Output("color_tex");
            lf_Output(texfname.c_str());
        }
    }
}

LxResult
MRZSaver::ss_Save ()
{
    initInfo();
    m_fps = GetFrameRate();
    
    StartScan();
    while(NextMesh())
        makeMeshInfo();
    StartScan();
    makeMaterialsInfo();
    
    lf_Output("MRZ");
    
    std::map<std::string, MaterialInfo>::const_iterator it, eit = m_matinfo.end();
    unsigned int nodenum = 1; // root
    std::map<std::string, std::map<std::string, unsigned int> >::const_iterator mit,meit = m_mesh_trinum.end();
    for (mit = m_mesh_trinum.begin(); mit != meit; ++mit) {
        //nodenum++;
        for (it = m_matinfo.begin(); it != eit; ++it) {
            auto fd = mit->second.find(it->first);
            if (fd != mit->second.end() && fd->second > 0 )
                nodenum++;
        }
    }
	nodenum += getWriteNodesCount();
    nodenum += m_matinfo.size();
    lf_Output(nodenum);
    
    unsigned char level = 0;
    lf_Output("GRP",-1);
    lf_Output(level);
    lf_Output("root");
    
    // Material
    ++level;
    writeMaterials(level);

    writeNodes();
    if (ReallySaving())
        writeAnimations();
    return LXe_OK;
}

void MRZSaver::ss_Polygon ()
{
    unsigned int n = PolyNumVerts();
    if (n < 3)
        return;
    const std::string& meshname = std::string(ItemName());
    const std::string& matname = PolyTag(LXi_PTAG_MATR);
    
    if (m_getpoly)
    {
        // count
        m_tricount[matname] += n - 2;
        
        // gather material
        m_mattable[matname] = 0;
        
        for (unsigned int i = 0; i < n; i++)
        {
            const VertexPolygon vp(PolyVertex(i), PolyID(), matname);
            m_vertexpoly.insert(vp);
        }
        //printf("PolyID=%ld\n", PolyID());
        return;
    }

    //write
    typedef std::map<PolygonVertex, unsigned int>::const_iterator const_itr;
    /*std::pair<const_itr,const_itr> eq = m_polyvertex.equal_range(PolygonVertex(PolyID(), PolyVertex(0)));
    for (const_itr it = eq.first; it != eq.second; ++it)
    {
        printf("PolyID[%g]-Vert[%g]\n", it->polyid, it->vertexid);
    }
    
    const_itr it0 = m_polyvertex.find(PolygonVertex(PolyID(), PolyVertex(0)));
    for (unsigned int i = 2; i < n; i++)
    {
        const_itr it1 = m_polyvertex.find(PolygonVertex(PolyID(), PolyVertex(i-1)));
        const_itr it2 = m_polyvertex.find(PolygonVertex(PolyID(), PolyVertex(i  )));
        printf("Tri(%d,%d,%d)\n",it0->vertexid, it1->vertexid, it2->vertexid);
        //m_poly[PolyID()] = TriID(PolyVertex(0), PolyVertex(i - 1), PolyVertex(i));
    }*/

    if (matname != m_targetMat)
        return;
    
    std::map<std::string, std::map<PolygonVertex, unsigned int> >::iterator it = m_mesh_polyvertex[meshname].find(matname);
    if (it == m_mesh_polyvertex[meshname].end())
        return;

    const unsigned int id0 = it->second[PolygonVertex(PolyID(), PolyVertex(0))];
    for (unsigned int i = 2; i < n; i++)
    {
        const unsigned int id1 = it->second[PolygonVertex(PolyID(), PolyVertex(i-1))];
        const unsigned int id2 = it->second[PolygonVertex(PolyID(), PolyVertex(i  ))];
        //printf("Tri(%d,%d,%d)\n",id0, id1, id2);
        lf_Output(static_cast<unsigned short>(id0));
        lf_Output(static_cast<unsigned short>(id1));
        lf_Output(static_cast<unsigned short>(id2));
        //m_poly[PolyID()] = TriID(PolyVertex(0), PolyVertex(i - 1), PolyVertex(i));
    }
    
    
}

void
MRZSaver::ss_Point ()
{
    float vec[3];
    PntPosition(vec);
    //float uv2[2];
    std::string meshname = std::string(ItemName());
    
    bool r = SetMap(LXi_VMAP_TEXTUREUV);
    float uv1[8] = {0.0f,0.0f};
    
    if (m_duplicateVertex)
    {
        std::set<VertexFormat> vertextable;
        typedef std::multiset<VertexPolygon>::const_iterator msetiterator;
        std::pair<msetiterator, msetiterator> range = m_vertexpoly.equal_range(VertexPolygon(PntID()));
        for (msetiterator it = range.first; it != range.second; ++it)
        {
            if (m_targetMat != it->mat)
                continue;

            //printf("V PointID:%ld PolyID:%ld\n", it->pntid, it->polyid);
            LXtVector normal;
            PntNormal(normal, it->polyid);
            PolySet(it->polyid);
            if (r)
                PolyMapValue(uv1, it->pntid);

            float nor[3] = {static_cast<float>(normal[0]), static_cast<float>(normal[1]), static_cast<float>(normal[2])};
            //int cc = vertextable.count(VertexFormat(vec, nor, uv1));
            vertextable.insert(VertexFormat(vec, nor, uv1));
            //printf("[Pos(%f,%f,%f) - uv(%f,%f)] - normal(%lf,%lf,%lf)\n", vec[0], vec[1], vec[2], uv1[0], uv1[1], normal[0], normal[1], normal[2] );
            
        }
        //printf("vertextable = %ld\n",vertextable.size());
        
        // Add
        std::set<VertexFormat>::const_iterator it,eit = vertextable.end();
        unsigned int addcount = 0;
        unsigned int lastcount = static_cast<unsigned int>(m_mesh_vertex[meshname][m_targetMat].size());
        for (it = vertextable.begin(); it != eit; ++it)
        {
            m_mesh_vertex[meshname][m_targetMat].push_back(*it);
            addcount++;
        }
        
        for (msetiterator it = range.first; it != range.second; ++it)
        {
            LXtVector normal;
            PntNormal(normal, it->polyid);
            PolySet(it->polyid);
            if (r)
                PolyMapValue(uv1, it->pntid);

            float nor[3] = {static_cast<float>(normal[0]), static_cast<float>(normal[1]), static_cast<float>(normal[2])};

            for (unsigned int vid = lastcount; vid < lastcount + addcount; vid++)
            {
                if (m_mesh_vertex[meshname][m_targetMat][vid] == VertexFormat(vec, nor, uv1))
                {
                    PolygonVertex pv(it->polyid, it->pntid);
                    m_mesh_polyvertex[meshname][m_targetMat][pv] = vid;
                    break;
                }
            }
        }
    }
}


/*
 * ----------------------------------------------------------------
 * Exporting Servers
 */
void
initialize ()
{
        //LXx_ADD_SERVER (Loader, MRZSaver, "vs_MRZ");
        LXx_ADD_SERVER (Saver,  MRZSaver,  "vs_MRZ"); // Saver only
}


