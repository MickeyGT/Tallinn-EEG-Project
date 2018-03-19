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
    public static int i1, i2, i3, i4, i5, i6, i7, i8; // intensity
    private int index;


    void Start()
    {
        udp = new UdpClient(56789);
        thread = new Thread(new ThreadStart(ThreadMethod));
        thread.Start();
        i1 = i2 = i3 = i4 = i5 = i6 = i7 = i8 = 1;
    }

    void splitValues(String data)
    {
        index = Data.IndexOf(' ');
        i1 = Int32.Parse(Data.Substring(0,index));
        Data = Data.Substring(index+1);
        index = Data.IndexOf(' ');
        i2 = Int32.Parse(Data.Substring(0, index));
        Data = Data.Substring(index + 1);
        index = Data.IndexOf(' ');
        i3 = Int32.Parse(Data.Substring(0, index));
        Data = Data.Substring(index + 1);
        index = Data.IndexOf(' ');
        i4 = Int32.Parse(Data.Substring(0, index));
        Data = Data.Substring(index + 1);
        index = Data.IndexOf(' ');
        i5 = Int32.Parse(Data.Substring(0, index));
        Data = Data.Substring(index + 1);
        index = Data.IndexOf(' ');
        i6 = Int32.Parse(Data.Substring(0, index));
        Data = Data.Substring(index + 1);
        index = Data.IndexOf(' ');
        i7 = Int32.Parse(Data.Substring(0, index));
        Data = Data.Substring(index + 1);
        index = Data.IndexOf('\n');
        i8 = Int32.Parse(Data.Substring(0, index));
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