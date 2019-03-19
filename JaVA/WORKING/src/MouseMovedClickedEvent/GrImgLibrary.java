package GrImgLibrary;

import java.io.File;
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

public class GrImgLibrary extends Frame implements
        WindowListener, MouseMotionListener, MouseListener {

    public int x, y, w, h;
    public int x1, y1, x2, y2, x3, y3;
    public int cr, cq, cb;
    public int d;
    public int cx, cy, dx, dy;

    String mouseEvent=null;
    String mouseMoveEvent=null;
    String mouseDragEvent;
    String ctrl;

    public String ms;

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

        Image img21=new ImageIcon("res/21.png").getImage();
        Image img29=new ImageIcon("res/29.png").getImage();

        BufferedImage img03,img04,img18,img23,img24;
        boolean fpic=false;

        img03=null;
        img04=null;
        img18=null;  
        img23=null;
        img24=null;

        try {
            img03=ImageIO.read(new File("res/03.png"));
            img04=ImageIO.read(new File("res/04.png"));
            img18=ImageIO.read(new File("res/18.png"));
            img23=ImageIO.read(new File("res/23.png"));
            img24=ImageIO.read(new File("res/24.png"));
            img23=ImageIO.read(new File("res/23.png"));
            img24=ImageIO.read(new File("res/24.png"));
            fpic=true;

        } catch (IOException e) {
            e.printStackTrace();
        }



        //TO DO draw

        h=img21.getHeight(null);
        w=img21.getWidth(null);

        if(fpic)
        {
            ms=" h="+h+" w="+w+" cx="+cx+" cy="+cy+" RH="+RH+" RW="+RW;
            g.drawString(ms,RH/80,RW/60+80);
            g.drawImage(img21,cx-w/2,cy-h/2,null);

            x1=RH-img04.getWidth()-20;
            y1=img04.getHeight()/4;
            g.drawImage(img04,x1,y1,null);

            x2=img24.getWidth()/4;
            y2=RW-img24.getHeight()-20;
            g.drawImage(img24,x2,y2,null);

            x3=RH-img03.getWidth()-20;
            y3=RW-img03.getHeight()-20;
            g.drawImage(img03,x3,y3,null);
        }


      if(toch!=null)
        {
            g.drawString(mouseMoveEvent,RH/80,RW/60+40);
            g.drawString(mouseEvent,RH/80,RW/60+60);

            x=toch.x;
            y=toch.y;


            if(x>cx-w/2 && x<cx+w/2 && y>cy-h/2 && y<cy+h/2)
            {
                g.drawImage(img29,cx-w/2,cy-h/2,null);
            }else
            {
                g.drawImage(img21,cx-w/2,cy-h/2,null);
            }

            if(x>x3&&x<RH&&y>y3&&y<RW)
            {
                g.drawImage(img18,x3,y3,null);
            }else
            {
                g.drawImage(img03,x3,y3,null);
            }

            if(x>x2&&x<x2+img24.getWidth()&&y>y2&&y<y2+img24.getHeight())
            {
                g.drawImage(img23,x2,y2,null);
            }else
            {
                g.drawImage(img24,x2,y2,null);
            }
        }


    }

    private static int rnd(int min, int max) {
        return (new Random()).ints(min,max).iterator().nextInt();
    }

    MouseAdapter mouseHandler = new MouseAdapter()
    {
        @Override
        public void mouseMoved(MouseEvent e) {
            toch = e.getPoint();
            mouseMoveEvent = "mouse move= " + x + "; " + y;
            //repaint();
        }

        @Override
        public void mouseClicked(MouseEvent e) {
            toch = e.getPoint();
            mouseEvent = "mouse click= " + x + "; " + y;
            repaint();
        }
    };

    public GrImgLibrary() {

        super("Програма керування графічними об'єктами.");
        addWindowListener(this);
        addMouseListener(mouseHandler);
        addMouseMotionListener(mouseHandler);
        setLayout(null);
        setLocation(120,100);
        setSize(800,600);
        show();
    }
}
