using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class GameManager : MonoBehaviour 
{
    //public static PlayData PlayerData;
    public NetManager mNetManager;
    //public static CallBackManager CallBackManager;

    void Awake()
    {
        DontDestroyOnLoad(this.gameObject);
        mNetManager = Utils.TryAddComponent<NetManager>(gameObject);
        //CallBackManager = Utils.TryAddComponent<CallBackManager>(gameObject);
    }

    void Start()
    {
        //SceneMgr.LoadScene(SCENE_CODE.LAUNCH);
    }
}
