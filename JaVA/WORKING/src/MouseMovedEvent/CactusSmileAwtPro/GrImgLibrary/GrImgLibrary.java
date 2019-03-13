package GrImgLibrary;

import java.util.Random;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.applet.*;

public class GrImgLibrary extends Frame implements
        WindowListener, MouseMotionListener, MouseListener {

    public int x,y,w,h;
    public int x1, y1, x2, y2;
    public int cr,cq,cb;
    public int d;
    public int cx, cy, dx, dy;

    String mouseEvent;
    String mouseMoveEvent;
    String mouseDragEvent;
    String ctrl;

    public String ms;

    public void windowOpened(WindowEvent e) {};

    public void windowClosing(WindowEvent e) {
        dispose();
        System.exit(0);
    };

    //int mouseX = 0, mouseY = 0;

    public void windowClosed(WindowEvent e) {};
    public void windowIconified(WindowEvent e) {};
    public void windowDeiconified(WindowEvent e) {};
    public void windowActivated(WindowEvent e) {};
    public void windowDeactivated(WindowEvent e) {};

    public void mouseMoved(MouseEvent e) {
        x=e.getPoint().x;
        y=e.getPoint().y;
    };
    public void mouseClicked(MouseEvent e) {
        x=e.getPoint().x;
        y=e.getPoint().y;
    };
    public void mousePressed(MouseEvent e) {};
    public void mouseReleased(MouseEvent e) {};
    public void mouseEntered(MouseEvent e) {};
    public void mouseExited(MouseEvent e) {};
    public void mouseDragged(MouseEvent e) {};

    class mouseClickedAdapter extends MouseAdapter
    {
        public void mouseClicked(MouseEvent e)
        {
            x=e.getPoint().x;
            y=e.getPoint().y;
            mouseEvent="mouse click= "+x+"; "+y;
            repaint();
        }
    }

    class mouseMovedAdapter extends MouseAdapter
    {
        public void mouseMoved(MouseEvent e)
        {
            x=e.getPoint().x;
            y=e.getPoint().y;
            mouseEvent="mouse move= "+x+"; "+y;
            repaint();
        }
    }



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

        //TO DO draw

        h=img21.getHeight(null);
        w=img21.getWidth(null);

        ms=" h="+h+" w="+w+" cx="+cx+" cy="+cy+" RH="+RH+" RW="+RW;
        g.drawString(ms,RH/80,RW/60+60);

        g.drawImage(img21,cx-w/2,cy-h/2,null);

        if(mouseEvent!=null)
        {
            g.drawString(mouseEvent,RH/80,RW/60+40);
            if(x>cx-w/2 && x<cx+w/2 && y>cy-h/2 && y<cy+h/2)
            {
                g.drawImage(img29,cx-w/2,cy-h/2,null);
            }else
            {
                g.drawImage(img21,cx-w/2,cy-h/2,null);
            }
        }

    }

    private static int rnd(int min, int max) {
        return (new Random()).ints(min,max).iterator().nextInt();
    }

    public GrImgLibrary() {
        super("Програма керування графічними об'єктами.");
        addWindowListener(this);
        addMouseMotionListener(new mouseMovedAdapter());
        addMouseListener(new mouseClickedAdapter());
        setLayout(null);
        setLocation(120,100);
        setSize(800,600);
        show();
    }
}

