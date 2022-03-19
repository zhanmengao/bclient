using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection;
using System.Text;
using UnityEngine;
using UnityEngine.SceneManagement;

public abstract class  SceneBase
{
    public abstract int SceneCode { get; }

    public abstract void OnLoadScene();

    public abstract void OnCloseScene();
}
public class SceneMgr
{
    public static SceneBase m_CurScene = null;

    private static Dictionary<int, SceneBase> m_SceneDir = new Dictionary<int, SceneBase>();


    static SceneMgr()
    {
        Type[] types = Assembly.GetAssembly(typeof(SceneBase)).GetTypes();
        foreach (var type in types)
        {
            if (type.FullName.EndsWith("Scene"))
            {
                SceneBase sb = Activator.CreateInstance(type) as SceneBase;
                if (sb != null)
                {
                    m_SceneDir.Add(sb.SceneCode, sb);
                }
            }
        }
    }

    public static void LoadScene(int scene)
    {
        //加载场景
        SceneManager.LoadScene(scene);
        if (m_CurScene != null)
        {
            m_CurScene.OnCloseScene();
        }
        SceneBase nextScene = GetScene(scene);
        if (nextScene != null)
        {
            m_CurScene = nextScene;
            nextScene.OnLoadScene();
        }
    }

    private static SceneBase GetScene(int scene)
    {
        SceneBase nextScene = null;
        if (m_SceneDir.TryGetValue(scene, out nextScene))
        {
            return nextScene;
        }
        return null;
    }
}

