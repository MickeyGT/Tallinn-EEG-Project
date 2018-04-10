using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using Affdex;
using UnityEditor;
using System.IO;

public class AffectivaProcess : ImageResultsListener
{
    private FeaturePoint[] featurePointsList;
    FeaturePoint fp;
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
            featurePointsList = face.FeaturePoints;
            foreach(FeaturePoint fp in featurePointsList)
            {
                DrawPoints.changeSphere(fp.id, fp.x, fp.y);
            }
        }
    }
}