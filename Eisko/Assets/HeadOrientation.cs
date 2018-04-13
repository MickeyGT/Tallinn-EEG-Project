using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using Affdex;
using UnityEditor;
using System.IO;

public class HeadOrientation : MonoBehaviour
{

    private static GameObject head;

    void Start()
    {
        head = GameObject.Find("Head_jnt");
    }

    void Update()
    {
        //Debug.Log("X:" + FaceControl.OrientationX + "Y:" + FaceControl.OrientationY);
        head.transform.rotation = Quaternion.Euler(FaceControl.OrientationX*-100,FaceControl.OrientationY*-100,head.transform.rotation.z);
    }

}