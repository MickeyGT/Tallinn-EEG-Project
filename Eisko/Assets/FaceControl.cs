using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using Affdex;
using UnityEditor;
using System.IO;

public class FaceControl : ImageResultsListener
{

    Transform mainCamera;
    CameraInput cameraInput;
    // Webcam name is needed since the Affectiva SDK isn't always picking the correct webcam.
    private string cameraName = "USB 2.0 Webcam Device";
    private string currentCameraName = "";
    // Variable that tells us if we will get data from Mirror, Machine Learning, File Reading, etc.
    private string processingType;
    // The emotion and expression values we get from Affectiva. (0-100)
    private float EyeClosure, Smirk, MouthOpen, Smile, BrowRaise, BrowFurrow,Disgust,
        Fear,Anger,Sadness,Surprise, Joy;
    SkinnedMeshRenderer skinnedMeshRenderer;
    Mesh skinnedMesh;
    public static float OrientationX, OrientationY,OrientationZ;

    public override void onFaceFound(float timestamp, int faceId)
    {
        Debug.Log("Found the face");
    }

    public override void onFaceLost(float timestamp, int faceId)
    {
        Debug.Log("Lost the face");
    }

    // Function that sets the blendshapes, can be used from any processingType, UDP for ML, Mirror for real-time and File for reading from a file. Should be between 0 and 100.
    public void setBlendShape(float EyeClosure, float Smirk, float MouthOpen, float Smile, float BrowRaise, float BrowFurrow, float Disgust,
       float Fear, float Anger, float Sadness, float Surprise, float Joy)
    {
        skinnedMeshRenderer.SetBlendShapeWeight(skinnedMesh.GetBlendShapeIndex("BS_node.Disgusted"), Disgust / 2);
        skinnedMeshRenderer.SetBlendShapeWeight(skinnedMesh.GetBlendShapeIndex("BS_node.Scared"), Fear);
        skinnedMeshRenderer.SetBlendShapeWeight(skinnedMesh.GetBlendShapeIndex("BS_node.Sad"), Sadness / 4);
        skinnedMeshRenderer.SetBlendShapeWeight(skinnedMesh.GetBlendShapeIndex("BS_node.Surprised"), Surprise / 3);
        skinnedMeshRenderer.SetBlendShapeWeight(skinnedMesh.GetBlendShapeIndex("BS_node.Angry"), Anger / 3);
        skinnedMeshRenderer.SetBlendShapeWeight(skinnedMesh.GetBlendShapeIndex("BS_node.Happy"), Joy * 3 / 4);
        skinnedMeshRenderer.SetBlendShapeWeight(skinnedMesh.GetBlendShapeIndex("BS_node.SUB_Mouth_Little_Opened"), MouthOpen / 4);
        skinnedMeshRenderer.SetBlendShapeWeight(skinnedMesh.GetBlendShapeIndex("BS_node.Smile_Lips_Closed"), Smile / 2);
        skinnedMeshRenderer.SetBlendShapeWeight(skinnedMesh.GetBlendShapeIndex("BS_node.Smirk"), Smirk / 2);
        skinnedMeshRenderer.SetBlendShapeWeight(skinnedMesh.GetBlendShapeIndex("BS_node.Eyes_Closed_Max"), EyeClosure);
        skinnedMeshRenderer.SetBlendShapeWeight(skinnedMesh.GetBlendShapeIndex("BS_node.Eyebrows_Raised"), BrowRaise);
        skinnedMeshRenderer.SetBlendShapeWeight(skinnedMesh.GetBlendShapeIndex("BS_node.Eyebrows_Frown"), BrowFurrow);
    }

    public override void onImageResults(Dictionary<int, Face> faces)
    {
        Debug.Log("Got face results");

        foreach (KeyValuePair<int, Face> pair in faces)
        {
            int FaceId = pair.Key;
            Face face = pair.Value;
            face.Expressions.TryGetValue(Expressions.Smile, out Smile);
            face.Expressions.TryGetValue(Expressions.EyeClosure, out EyeClosure);
            face.Expressions.TryGetValue(Expressions.MouthOpen, out MouthOpen);
            face.Expressions.TryGetValue(Expressions.Smirk, out Smirk);
            face.Expressions.TryGetValue(Expressions.BrowRaise, out BrowRaise);
            face.Expressions.TryGetValue(Expressions.BrowFurrow, out BrowFurrow);
            face.Emotions.TryGetValue(Emotions.Disgust, out Disgust);
            face.Emotions.TryGetValue(Emotions.Fear, out Fear);
            face.Emotions.TryGetValue(Emotions.Anger, out Anger);
            face.Emotions.TryGetValue(Emotions.Sadness, out Sadness);
            face.Emotions.TryGetValue(Emotions.Surprise, out Surprise);
            face.Emotions.TryGetValue(Emotions.Joy, out Joy);
            // Getting the orientation for rotating the head.
            OrientationX = face.Measurements.Orientation.x;
            OrientationY = face.Measurements.Orientation.y;
            OrientationZ = face.Measurements.Orientation.z;
        }
    }

    void Start ()
    {
        OrientationX = OrientationY = 0;
        // Standard processing type.
        processingType = "Mirror";
    }

	void Update ()
    {
        if (currentCameraName != cameraName)
        {
            cameraInput.SelectCamera(true, cameraName);
            currentCameraName = cameraName;
        }
        if(processingType=="Mirror")
        {
            setBlendShape(EyeClosure,Smirk,MouthOpen,Smile,BrowRaise,BrowFurrow,Disgust,Fear,Anger,Sadness, Surprise, Joy);
        }
        else
            if(processingType=="UDP")
            {
                //to be continued
            }
    }

    void Awake()
    {
        mainCamera = GameObject.FindGameObjectWithTag("MainCamera").transform;
        cameraInput = mainCamera.GetComponent<CameraInput>();
        skinnedMeshRenderer = GetComponent<SkinnedMeshRenderer>();
        skinnedMesh = GetComponent<SkinnedMeshRenderer>().sharedMesh;
    }
}
