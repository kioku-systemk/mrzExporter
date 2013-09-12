#modoエクスポータ解説(2013.9.9)
Twitter:@kioku_systemk

modoのエクスポータ解説はWeb上であまり見られないので、ここに備忘録的に書いておきます。

細かくやるときりがないので、導入の部分とつまづきそうな部分を中心に解説していきます。

## 概要
基本的なエクスポータのコードの概要は以下の通りである。
modoのAPIはCOMなのだが、いくつかの便利ラッパークラスが提供されているので
それを利用すると作成が便利である。

    #if 0
    // Text Format Mode
    class MySaver : public CLxSceneSaver, public CLxLineFormat
    {
       ...
    }
    
    #else
    // Binary Format Mode
    class MySaver : public CLxSceneSaver, public CLxBinaryFormat
    {
       ...
    }
    
    #endif
    
    void initialize ()
    {
        LXx_ADD_SERVER (Saver,  MySaver,  "vs_MYF");
    }


modoのエクスポータはCLxSceneSaverクラスを継承してつくります。
initialize()関数で作成したクラスを登録します。
ここではエクスポータのみを登録していますが、Loaderも同様に登録可能です。
バイナリフォーマットにするか、テキストフォーマットかは
CLxFileFormatクラスを継承したCLxBinaryFormatかCLxLineFormatを
利用するかで選ぶことが可能です。
modoではCLxXXXFormatクラスを利用したファイル書き込みが必要です。
このクラスのff_Open()などのファイルオープン関数を利用せず、独自でfopen()などの処理を
行うと、保存時にファイル保存エラーがでるようになるので注意が必要です。


## 純粋仮想関数の定義

CLxSceneSaverクラスを継承すると、いくつかの仮想関数とかを実装する必要が有ります。
必要な関数はこちら。

    class CLxSceneSaver{
    public:
      ...
      virtual CLxFileFormat	*ss_Format    ();
      virtual LxResult	 ss_Save      ();
      
      static LXtTagInfoDesc descInfo[];
      ...
    }


ss_Format関数はBinaryFormatかLineFormatなのかを知らせるために利用されます。
ここでは継承を利用して実装しているので、thisポインタを返せばよいことになります。

    CLxFileFormat* MySaver::ss_Format()
    {
       return this;
    }

ss_Save関数はエクスポートを行う際に呼ばれるメインの関数です。
この中でエクスポートに必要な処理をおこないます。

以下のように書くと、AAAとかかれたファイルが出力されます。
    
    LxResult MySaver::ss_Save()
    {
       lf_Output("AAA")
    }

ファイルオープン処理などは先のss_Formatが自動で呼び出されファイルはオープンされた状態にあります。ss_Save()の中では書き込み処理のみを行えば良いです。

注意点として、このss_Save()は１回の保存で２度呼ばれます。
理由は、modoで保存に時間のかかるファイルなどで、プログレスバーが表示されますが、
このプログレスバーを表示するために、エクスポータが何回ファイル書き込みを行うかなどを
modoかカウントするためのようです。
1度目のss_Save()呼び出しではlf_Output()などを呼び出しても実際には書き込まれず、
2度目のss_Save()呼び出しで実際の書き込みを行っている様です。
この、いずれかの状態を知りたいときは、以下の判定を用いますが、
通常はあまり気にする必要は有りません。

    if (ReallySaving())
    {
        //本当に書き込もうとしている時に実行される
    }
    else
    {
       //それ以外
    }
 
関数ではないですが、配列に拡張子とかの情報を設定する必要が有ります。

    LXtTagInfoDesc	 MySaver::descInfo[] = {
        { LXsSAV_OUTCLASS,	LXa_SCENE	},
        { LXsSAV_DOSTYPE,	"MYF"		},   // 拡張子
        { LXsSRV_USERNAME,	"My Format" },   // ファイル保存ダイアログに表示されるテキスト
        { 0 }                                // 終端
    };


## アイテムノードの取得

modoのデータ構造の取得にはいくつかの便利関数が用意されています。

    void MySaver::ScanNodes()
    {
    	StartScan();
    	while(NextItem()){
    		CLxLoc_Item item;
		if (GetItem(item)) {
			...
		}
		SetItem(item);
        }
    }

NextItem()関数でmodoのアイテムリストのノードに接続されたアイテムを順番に走査することができます。
NextItem()でアイテムノードのポインタをすすめ、GetItem()でアイテムノードを取得します。
必要な処理をしたあと、SetItem()を呼び出していますが、
これは再帰処理や、別のアイテムをセットした後に呼び出しておかないと、
NextItem()で正しく次のアイテムノードが呼び出されなくなります。



## アイテムノードのツリー構造

アイテムノードの情報は先に取得したCLxLoc_Item item;から取得します。
先のNextItem()で走査されるノードはツリー構造など関係なく、すべてのノードを
走査してしまうので、ツリー構造を取得するためには向いていません。
アイテムのツリー構造を取得するには自分でアイテムが子ノードを持っているか調べる必要があります。

以下の判定を加えることでアイテムノードのルートのみに処理を行うようにします

    void MySaver::ScanRootNodes()
    {
    	StartScan();
    	while(NextItem()){
	    	CLxLoc_Item item;
	    	if (GetItem(item)) {
	    		// Check root node
	    		LXtObjectID	parent = NULL;
                if (item.Parent (reinterpret_cast<void**>(&parent)) == LXe_OK) {
                    lx::ObjRelease (parent);
                    continue;　// skip non-root node
                }
		    	CLxUser_Item uitem(item);
		    	ScanChildNodes(uitem);
		    }
	    	SetItem(item);
        }
    }

CLxUser_Itemにitemを変換していますが、これは子階層を
トラバースする処理するのに向いているのでScanChildNodesに渡す前に変換しています。
次に、ルートノードを基準に子階層をトラバースする処理を加えます。

    void MySaver:ScanChildNodes(CLxUser_Item& item)
    {
    	SomethingTodo(item);

        unsigned int cnt = 0;
        if (item.SubCount(&cnt) != LXe_OK)
            return;
        for (unsigned int i = 0; i < cnt; ++i)
    	{
            LXtObjectID	sub = NULL;
            if (item.SubByIndex(i, reinterpret_cast<void**>(&sub)) != LXe_OK)
                continue;
            
            CLxUser_Item subitem;
            subitem.set(sub);
            ScanChildNodes(subitem); // recursive
        }
    }

トラバースする際に気を付けないといけないのは、modoのアイテムリストのツリーのトップに
複数のノードがある場合、ルートが複数存在するようになります。

##ノードのタイプ判定処理

SetItem(item)されている状態で、
以下の判定文を加えることでノードタイプを判定することができます。

    if (ItemIsA (LXsITYPE_MESH))
    	// mesh node
    else if (ItemIsA (LXsITYPE_CAMERA))
    	// camera node
    else if (ItemIsA (LXsITYPE_LOCATOR))
    	// Locator node
    ...

ノードタイプはいくつかの種類があります。LXsITYPE_XXXの定義をしらべてください。


## チャンネル情報の取得
modoではノードにプロパティのトランスフォームからつけられた
平行移動、回転情報、拡大縮小情報などはチャンネルとよばれる部分に集約されています。
実際にはマトリックスの乗算順が問題になり、チャンネル情報をトラバースすることにより
必要な順序でトランスフォーム計算できるようになります。

    void ChannelTraverse(CLxUser_Item& item)
    {
    	CLxUser_Scene      scene(SceneObject ());
    	CLxUser_SceneGraph sceneGraph;
        CLxUser_ItemGraph  itemGraph;
        scene.GetGraph (LXsGRAPH_XFRMCORE, sceneGraph);
        itemGraph.set (sceneGraph);

    	unsigned transformCount = itemGraph.Reverse (item);
        for (unsigned transformIndex = 0; transformIndex < transformCount; ++transformIndex) {
            CLxUser_Item transform;
            if (itemGraph.Reverse (item, transformIndex, transform)) {
                SetItem (transform);
    			
    			const char *xformType = ItemType ();
                if (std::string(xformType) == std::string(LXsITYPE_SCALE)) {
    				// scale
    				LXtVector	scale;
                    ChanXform (LXsICHAN_SCALE_SCL, scale);
                    
    			}else if (std::string(xformType) == std::string(LXsITYPE_ROTATION)){
    				// Rotation
    				LXtVector rotate;
                    ChanXform (LXsICHAN_ROTATION_ROT, rotate);
                    int axis[3];
                    buildAxisOrder (ChanInt (LXsICHAN_ROTATION_ORDER), axis);
                    
    			}else if (std::string(xformType) == std::string(LXsITYPE_TRANSLATION)) {
    				// Translation
    				LXtVector	translate;
                    ChanXform (LXsICHAN_TRANSLATION_POS, translate);
                   
    			}
    		}
    	}
    }

Rotationは回転順序が設定できるのでこれを別途取得しておく必要があります。
回転順序の番号を生成するのは次の関数

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
                axis[0] = 0; axis[1] = 2; axis[2] = 1;
                break;
            case ROTATION_ORDER_YXZ:
                axis[0] = 1; axis[1] = 0; axis[2] = 2;
                break;
            case ROTATION_ORDER_YZX:
                axis[0] = 1; axis[1] = 2; axis[2] = 0;
                break;
            case ROTATION_ORDER_ZXY:
                axis[0] = 2; axis[1] = 0; axis[2] = 1;
                break;
            case ROTATION_ORDER_ZYX:
                axis[0] = 2; axis[1] = 1; axis[2] = 0;
                break;
            case ROTATION_ORDER_XYZ:
            default:
                axis[0] = 0; axis[1] = 1; axis[2] = 2;
            break;
        }
    }


## ポリゴン、ポイント情報の取得
modoで用意されたインターフェースはScanItem(); NextItem()で
データを書き込むのに向いたインターフェースでつくられているようで、
meshノードがSetItem()された状態で、以下の関数を呼び出す必要があります。

    CLxSceneSaver::WritePolys();
    //	ポリゴンの数分ss_Polygon()が呼び出されます。

    CLxSceneSaver::WrietPoints();
    //	ポイントの数分ss_Point()が呼び出されます。

上記関数を呼び出す前にCLxSceneSaver::ss_Polygon(), ss_Point()の
関数をオーバーライドしておく必要があります。

以下例です。

    void MySaver::ss_Polygon ()
    {
        unsigned int n = PolyNumVerts();
    	const std::string& meshname = std::string(ItemName());
        for (unsigned int i = 0; i < n; i++)
        {
    		LXtPolygonID id = PolyID();
        }
    }
    
    void MySaver::ss_Point ()
    {
    	std::string meshname = std::string(ItemName());
        
        float vec[3];
        PntPosition(vec); // 頂点情報の取得
        
    	float uv1[8] = {0.0f,0.0f};
        bool r = SetMap(LXi_VMAP_TEXTUREUV);
        if (r)
            PntMapValue(uv1); // UV情報の取得
    }

法線情報の取得に関しては少し面倒で、PolyonIDに関連付けられた法線を取得する必要があります。
ss_Point()関数内で、以下の呼び出しで取得可能です。

     LXtVector normal;
     PntNormal(normal, polyid);
          
頂点ごとの法線が必要な場合、ss_Point内でpolyonidが必要になるので
事前にWritePoly()を呼び出し、ss_Polygon()で自前のデータ構造にストアしておく必要があります。


## マテリアル情報の取得

ポリゴンのマテリアル情報はタグでつけられているだけなので、
ss_Polygon()内で以下の呼び出しで取得可能です。

     const std::string& matname = PolyTag(LXi_PTAG_MATR);
    
またマテリアル自体の情報はレイヤーを走査することで取得可能です。

    ScanMask(matname);
    while (NextLayer ())
    {
        if (ItemIsA (LXsITYPE_ADVANCEDMATERIAL))
        {
            std::string name = ItemName();
            float rgb[3];
            rgb[0] = ChanFloat (LXsICHAN_ADVANCEDMATERIAL_DIFFCOL".R");
            rgb[1] = ChanFloat (LXsICHAN_ADVANCEDMATERIAL_DIFFCOL".G");
            rgb[2] = ChanFloat (LXsICHAN_ADVANCEDMATERIAL_DIFFCOL".B");   
    	}
    	else if (ItemIsA (LXsITYPE_IMAGEMAP))
        {
            std::string fx = LayerEffect ();
            if (fx == LXs_FX_DIFFCOLOR)
            {
                if (TxtrImage())
                    std::string texturename = ChanString (LXsICHAN_VIDEOSTILL_FILENAME);
            }
        }
    }

## アニメーション情報の取得
ここでのアニメーションはノードにつけられるトランスフォームのアニメーションに限定します。
ノードのトランスフォームについている情報なので、先のノードのトランスフォームと同様の
トラバース処理を行います。
そして、アニメーションを取得したいトランスフォームがSetItemされている状態で
ChanEnvelope()で取得可能です。

    void MySaver::GetChan(channame)
    {
    	CLxUser_Keyframe key;
        CLxUser_Envelope envelope;
        if (ChanEnvelope (channame, envelope)){
            envelope.GetKeyframe(&key);
            while (key.Next() == LXe_OK){
                ...
    		}
        }
    }

ChanEnvelopeで設定可能なchannameは次の通りです。

    const char *xformType = ItemType ();
    if (std::string(xformType) == std::string(LXsITYPE_SCALE)) {
    	GetChan("scl.X");
    	GetChan("scl.Y");
    	GetChan("scl.Z");
    } else if (std::string(xformType) == std::string(LXsITYPE_ROTATION)) {
    	GetChan("rot.X");
    	GetChan("rot.Y");
    	GetChan("rot.Z");
    } else if (std::string(xformType) == std::string(LXsITYPE_TRANSLATION)) {
    	GetChan("pos.X");
    	GetChan("pos.Y");
    	GetChan("pos.Z");
    }

取得した CLxUser_Keyframe key; から時間とキーの値を取得可能です。


## まとめ

だいたいエクスポータの概要はこんなところです。
単純に頂点情報とポリゴン情報を出すだけなら、ss_Point()/ss_Polygon()で
lf_Output()を呼び出しで取得したデータをその場で書き出せばよいのですが、
独自のビューワなどで利用するようなエクスポータを作ろうとする場合、
頂点ごとに別の法線がついている場合に頂点の複製をしたり、
階層ごとにポリゴン頂点データを取得したい場合は、事前にss_Point/ss_Polygonで
独自のデータ構造にノード名とともに格納しておき、
階層のトラバース時に独自のデータ構造からデータを取得するような処理になります。

というわけで、これからmodoのエクスポータを作成するひとの多少なりとも足がかりになれば幸いです。
個人的な予測(希望)ですが、2020年ころにはMayaに代わる3D作成ツールとしてmodoは幅を利かせているでしょう。
という予言をしておきます。笑
