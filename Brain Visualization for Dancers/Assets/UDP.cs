using UnityEngine;
using System.Collections;
using System.Net;
using System.Net.Sockets;
using System.Text;
using System.Threading;
using System;
using System.Security.Permissions;

public class UDP : MonoBehaviour
{
    Thread thread;
    bool precessData = false;
    private string Data;
    private UdpClient udp;
    private bool running = true;
    public static int[] intensities = new int[9]; // intensity
    private int index;


    void Start()
    {
        udp = new UdpClient(56789);
        thread = new Thread(new ThreadStart(ThreadMethod));
        thread.Start();
        for (int i = 1; i <= 8; i++)
            intensities[i] = 0;
    }

    void splitValues(String data)
    {
        for(int i=1;i<=7;i++)
        {
            index = Data.IndexOf(' ');
            intensities[i]= Int32.Parse(Data.Substring(0, index));
            Data = Data.Substring(index + 1);
        }
        intensities[8] = Int32.Parse(Data);
    }

    void Update()
    {
        if (precessData)
        {
            precessData = false;
            //Process received data
            splitValues(Data);
            Debug.Log("Received: " + Data);
        }
    }


    [SecurityPermissionAttribute(SecurityAction.Demand, ControlThread = true)]
    private void KillTheThread()
    {
        thread.Abort();
    }

    void OnApplicationQuit()
    {
        udp.Close();
        running = false;
        KillTheThread();

    }

    private void ThreadMethod()
    {
        while (running)
        {
            IPEndPoint RemoteIpEndPoint = new IPEndPoint(IPAddress.Any, 0);
            try
            {
                Byte[] receiveBytes = udp.Receive(ref RemoteIpEndPoint);
                Data =Encoding.ASCII.GetString(receiveBytes);
                Debug.Log(Data);
                //Done, notify the Update function
                precessData = true;
            }
            catch (Exception e)
            {
                Console.WriteLine(e.ToString());
            }
        }
    }
}