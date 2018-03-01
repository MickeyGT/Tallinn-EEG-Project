using UnityEngine;
using System.Collections;
using System.Net;
using System.Net.Sockets;
using System.Text;
using System.Threading;
using System;

public class UDP : MonoBehaviour
{
    Thread thread;
    static readonly object lockObject = new object();
    bool precessData = false;
    public static int power;

    void Start()
    {
        power = 1;
        thread = new Thread(new ThreadStart(ThreadMethod));
        thread.Start();
    }

    void Update()
    {
        if (precessData)
        {
            precessData = false;
            //Process received data
            Debug.Log("Received: " + power);
        }
    }

    void OnApplicationQuit()
    {
        //udp.Close();
        thread.Abort();
    }

    private void ThreadMethod()
    {
        UdpClient udp = new UdpClient(12345);
        while (true)
        {
            IPEndPoint RemoteIpEndPoint = new IPEndPoint(IPAddress.Any, 0);
            try
            {
                Byte[] receiveBytes = udp.Receive(ref RemoteIpEndPoint);
                power = Int32.Parse(Encoding.ASCII.GetString(receiveBytes));
                Debug.Log(power);
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