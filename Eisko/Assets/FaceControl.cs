using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using Affdex;
using UnityEditor;
using System.IO;
using Affdex;

public class FaceControl : ImageResultsListener
{

    Transform mainCamera;
    CameraInput cameraInput;
    string cameraName = "USB 2.0 Webcam Device";
    string currentCameraName = "";
    private float EyeClosure, Smirk, MouthOpen, Smile, BrowRaise, BrowFurrow,Disgust,
        Fear,Anger,Sadness,Surprise, Joy;
    SkinnedMeshRenderer skinnedMeshRenderer;
    Mesh skinnedMesh;


    public override void onFaceFound(float timestamp, int faceId)
    {
        Debug.Log("Found the face");
    }

    public override void onFaceLost(float timestamp, int faceId)
    {
        Debug.Log("Lost the face");
    }

    public override void onImageResults(Dictionary<int, Face> faces)
    {
        Debug.Log("Got face results");

        foreach (KeyValuePair<int, Face> pair in faces)
        {
            int FaceId = pair.Key;  // The Face Unique Id.
            Face face = pair.Value;
            face.Expressions.TryGetValue(Expressions.Smile, out Smile);
            face.Expressions.TryGetValue(Expressions.EyeClosure, out EyeClosure);
            face.Expressions.TryGetValue(Expressions.MouthOpen, out MouthOpen);
            face.Expressions.TryGetValue(Expressions.Smirk, out Smirk);
            face.Expressions.TryGetValue(Expressions.BrowRaise, out BrowRaise);
            face.Expressions.TryGetValue(Expressions.BrowRaise, out BrowFurrow);
            face.Emotions.TryGetValue(Emotions.Disgust, out Disgust);
            face.Emotions.TryGetValue(Emotions.Fear, out Fear);
            face.Emotions.TryGetValue(Emotions.Anger, out Anger);
            face.Emotions.TryGetValue(Emotions.Sadness, out Sadness);
            face.Emotions.TryGetValue(Emotions.Surprise, out Surprise);
            face.Emotions.TryGetValue(Emotions.Joy, out Joy);
            skinnedMeshRenderer.SetBlendShapeWeight(skinnedMesh.GetBlendShapeIndex("BS_node.Smile_Lips_Closed"), Smile);
            skinnedMeshRenderer.SetBlendShapeWeight(skinnedMesh.GetBlendShapeIndex("BS_node.Smirk"), Smirk);
            skinnedMeshRenderer.SetBlendShapeWeight(skinnedMesh.GetBlendShapeIndex("BS_node.Eyes_Closed_Max"), EyeClosure);
            skinnedMeshRenderer.SetBlendShapeWeight(skinnedMesh.GetBlendShapeIndex("BS_node.SUB_Mouth_Little_Opened"), MouthOpen);
            skinnedMeshRenderer.SetBlendShapeWeight(skinnedMesh.GetBlendShapeIndex("BS_node.Eyebrows_Raised"), BrowRaise);
            skinnedMeshRenderer.SetBlendShapeWeight(skinnedMesh.GetBlendShapeIndex("BS_node.Eyebrows_Frown"), BrowFurrow);
            skinnedMeshRenderer.SetBlendShapeWeight(skinnedMesh.GetBlendShapeIndex("BS_node.Disgusted"), Disgust);
            skinnedMeshRenderer.SetBlendShapeWeight(skinnedMesh.GetBlendShapeIndex("BS_node.Scared"), Fear);
            skinnedMeshRenderer.SetBlendShapeWeight(skinnedMesh.GetBlendShapeIndex("BS_node.Sad"), Sadness);
            skinnedMeshRenderer.SetBlendShapeWeight(skinnedMesh.GetBlendShapeIndex("BS_node.Surprised"), Surprise);
            skinnedMeshRenderer.SetBlendShapeWeight(skinnedMesh.GetBlendShapeIndex("BS_node.Angry"), Anger);
            skinnedMeshRenderer.SetBlendShapeWeight(skinnedMesh.GetBlendShapeIndex("BS_node.Happy"), Joy);
        }
    }

    void Start ()
    {

    }

	void Update ()
    {
        if (currentCameraName != cameraName)
        {
            cameraInput.SelectCamera(true, cameraName);
            currentCameraName = cameraName;
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
