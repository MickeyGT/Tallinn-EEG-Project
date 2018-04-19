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
            // With each new update to the feature point location, we change the corresponding sphere.
            foreach(FeaturePoint fp in featurePointsList)
            {
                DrawPoints.changeSphere(fp.id, fp.x, fp.y);
            }

            // We place the sphere for the right and left eye between the 4 feature points that contour the eyes.
            DrawPoints.changeLeftEye((featurePointsList[18].x+ featurePointsList[19].x + featurePointsList[32].x + featurePointsList[33].x)/4, (featurePointsList[32].y + featurePointsList[33].y + featurePointsList[18].y + featurePointsList[19].y)/4);
            DrawPoints.changeRightEye((featurePointsList[16].x + featurePointsList[17].x + featurePointsList[30].x + featurePointsList[31].x)/4, (featurePointsList[16].y + featurePointsList[17].y + featurePointsList[30].y + featurePointsList[31].y)/4);
        }
    }
}