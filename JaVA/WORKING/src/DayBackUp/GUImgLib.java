package GUImgLib;
import java.io.File;
import java.nio.CharBuffer;
import java.util.Arrays;
import java.util.Random;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.image.BufferedImage;
import java.io.*;

import javax.imageio.ImageIO;
import javax.swing.ImageIcon;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.io.IOException;
import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.util.Scanner;

public class GUImgLib extends  Frame implements
        WindowListener, MouseMotionListener, MouseListener {

    public int x, y, w, h;
    public int x1, y1, x2, y2, x3, y3;
    public int cr, cq, cb;
    public int d;
    public int cx, cy, dx, dy;

    String mouseEvent="";
    String mouseMoveEvent="";
    String mouseDragEvent="";
    String ctrl="";

    public String ms="";

    public void windowOpened(WindowEvent e) {    }    ;

    public void windowClosing(WindowEvent e) {
        dispose();
        System.exit(0);
    };

    public void windowClosed(WindowEvent e) { };
    public void windowIconified(WindowEvent e) { };
    public void windowDeiconified(WindowEvent e) { };
    public void windowActivated(WindowEvent e) { };
    public void windowDeactivated(WindowEvent e) { };
    public void mouseMoved(MouseEvent e) { };
    public void mouseClicked(MouseEvent e) { };
    public void mousePressed(MouseEvent e) { };
    public void mouseReleased(MouseEvent e) { };
    public void mouseEntered(MouseEvent e) { };
    public void mouseExited(MouseEvent e) { };
    public void mouseDragged(MouseEvent e) { };


    public Point toch=null;
    public int count=0;

    public void paint(Graphics g) {

        Dimension rc = getSize();
        Insets in = getInsets();

        int RH = rc.width;
        int RW = rc.height;

        int minX = in.left;
        int maxX = RH - in.right;
        int minY = in.top;
        int maxY = RW - in.bottom;

        float wdk=3.0f;

        cx = Math.abs(maxX - minX) / 2;
        cy = Math.abs(maxY - minY) / 2;
        dx = maxX / 10;
        dy = maxY / 10;

        Graphics2D g2 = (Graphics2D) g;
        g2.setStroke(new BasicStroke(wdk));

        // TO DO init

        boolean fpic=false;
        x1 = 20;
        y1 = 70;
        dx = 158;
        dy = 95;

        BufferedImage[]  imgkw=new BufferedImage[20];
        for (int i = 1; i <=18 ; i++) {
            imgkw[i]=null;
        }

        try {
            for (int i = 1; i <=18 ; i++) {
                if (i<10) ms="res/k0"+i+".png";
                else ms="res/k"+i+".png";
                imgkw[i]=ImageIO.read(new File(ms));
            }
            fpic=true;
        } catch (IOException e) {
            e.printStackTrace();
        }

        count=0; // window.close
        try {
            FileReader reader = new FileReader("data.txt");
            char[] buf = new char[1];
            int c=0;
            while((c = reader.read(buf))!=-1)
            {
                count++;
            }
            reader.close();
        } catch (IOException e) {
            e.printStackTrace();
        }

        int[] kwdX=new int[19];
        int[] kwdY=new int[19];

        //TO DO draw

        if(fpic)
        {
            int p = 1;
            for (int k = 0; k < 3; k++)
            {
                x=x1; y=y1+k*dy;
                for (int i = 0; i < 6; i++)
                {
                    g.drawImage(imgkw[p], x, y, null);
                    g.setFont(new Font("Trebuchet Ms", Font.BOLD, 20));
                    g.setColor(new Color(44, 21, 186));
                    ms="";ms+=p;
                    g.drawString(ms,x+dx/2-10,y+dy-8);
                    kwdX[p]=x-2;kwdY[p]=y-2;
                    p++; x+=dx;
                }
            }

        }

        if(toch!=null) {
            x = toch.x;
            y = toch.y;
            for (int p = 1; p < 19; p++) {
                if (x > kwdX[p] && x < kwdX[p]+dx &&
                        y > kwdY[p] && y < kwdY[p]+dy)
                {
                    int wnd=p;
                    g.setColor(new Color(69, 35,105));
                    g2.setStroke(new BasicStroke(5));
                    g.drawRect(kwdX[p],kwdY[p],dx,dy-1);

                    if (count == 5)
                    {
                        String txt = "";
                        try {
                            FileWriter writer = new FileWriter("data.txt");
                            txt+=wnd;
                            writer.write(txt);
                            writer.flush();
                            writer.close();
                        } catch (IOException e) {
                            e.printStackTrace();
                        }
                        new GUWindow01();
                    }
                }
            }
        }
    }

/*
    private static int rnd(int min, int max) {
        return (new Random()).ints(min,max).iterator().nextInt();
    }
*/

    MouseAdapter mouseHandler = new MouseAdapter()
    {
        @Override
        public void mouseMoved(MouseEvent e) {
            toch=null;
            toch = e.getPoint();
            mouseMoveEvent = "mouse move= " + x + "; " + y;
            //repaint();
        }

        @Override
        public void mouseClicked(MouseEvent e) {
            toch=null;
            toch = e.getPoint();
            mouseEvent = "mouse click= " + x + "; " + y;
            repaint();
        }
    };

    public GUImgLib() {

        super("Проект з теми: День бекапу.");
        addWindowListener(this);
        addMouseListener(mouseHandler);
        addMouseMotionListener(mouseHandler);
        setLayout(null);
        setLocation(20,50);
        setSize(990,400);
        this.setResizable(false);

        // TO DO init
        Image icon=new ImageIcon("res/STEAmProject.png").getImage();
        this.setIconImage(icon);

        show();
    }
}