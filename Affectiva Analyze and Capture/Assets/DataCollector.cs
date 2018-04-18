using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using Affdex;
using UnityEditor;
using System.IO;

    public class DataCollector : ImageResultsListener
{
    public float currentSmile;
    public float currentInterocularDistance;
    public float currentContempt;
    public float currentValence;
    public float currentAnger;
    public float currentFear;
    public FeaturePoint[] featurePointsList;

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
            Face face = pair.Value;    // Instance of the face class containing emotions, and facial expression values.

            using (StreamWriter sw = new StreamWriter("CollectedData.txt",true))
            {
                // The ToString function has been modified so it writes to file in the needed format. See Face.cs for format.
                sw.WriteLine(face.ToString());
            }
        }
    }
}
