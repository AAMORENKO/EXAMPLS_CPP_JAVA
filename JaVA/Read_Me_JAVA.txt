package WinGrLib;


import java.awt.*;
import java.awt.event.*;
import java.util.Random;

public class WinGrLib extends Frame implements WindowListener, MouseListener, MouseMotionListener {

    String mouseEvent = null;
    String mouseMoveEvent = null;
    String mouseDragEvent;
    String ctrl;
    public Point toch = null;
    public int x, y, w, h;
    final public double PI = 3.14159265359;

    public void windowOpened(WindowEvent e) {
    }

    ;

    public void windowClosing(WindowEvent e) {
        dispose();
        System.exit(0);
    }

    ;

    public void windowClosed(WindowEvent e) {
    }

    ;

    public void windowIconified(WindowEvent e) {
    }

    ;

    public void windowDeiconified(WindowEvent e) {
    }

    ;

    public void windowActivated(WindowEvent e) {
    }

    ;

    public void windowDeactivated(WindowEvent e) {
    }

    ;

    public void mouseClicked(MouseEvent e) {
    }

    ;

    public void mousePressed(MouseEvent e) {
    }

    ;

    public void mouseReleased(MouseEvent e) {
    }

    ;

    public void mouseEntered(MouseEvent e) {
    }

    ;

    public void mouseExited(MouseEvent e) {
    }

    ;

    public void mouseDragged(MouseEvent e) {
    }

    ;

    public void mouseMoved(MouseEvent e) {
    }

    ;


    public void paint(Graphics g) {
        Dimension rc = getSize();
        Insets in = getInsets();

        int RH = rc.width;
        int RW = rc.height;

        int minX = in.left;
        int maxX = RH - in.right;
        int minY = in.top;
        int maxY = RW - in.bottom;

        int cx, cy, dx, dy;

        int x1, y1, x2, y2, x3, y3;

        Graphics2D g2 = (Graphics2D) g;
        g2.setStroke(new BasicStroke(1.0f));

        cx = Math.abs(maxX - minX) / 2;
        cy = Math.abs(maxY - minY) / 2 + 50;
        dx = 40;
        dy = 20;

        // TODO THIS PAINT
        float wdk = 2.5f;
        g2.setStroke(new BasicStroke(wdk));
        g2.setColor(new Color(0, 0, 0));

        int[][] knp = new int[8][2];
        int[] clr = new int[]{0x000, 0x0032CD32, 0xEC00CE, 0x00CC97,
                0x8B0679, 0xED2873, 0xFA613E, 0x351BFF, 0xFFF84A};
        int c1, c2, c3;
        x1 = minX + 20;
        y1 = minY + 20;
        for (int i = 0; i < 8; i++) {
            knp[i][0] = x1;
            knp[i][1] = y1;
            g2.setColor(new Color(0, 0, 0));
            g2.drawRect(x1, y1, dx, dy);
            c1 = rnd(1, 255);
            c2 = rnd(1, 255);
            c3 = rnd(1, 255);
            if (i == 0) {
                g2.setColor(new Color(c1, c2, c3));
                g2.fillRect(x1, y1, dx, dy);
            }
            if (i > 0 && i < 7) {
                g2.setColor(new Color(clr[i]));
                g2.fillRect(x1, y1, dx, dy);
            }
            if (i == 7) {
                g2.setColor(new Color(clr[i+1]));
                g2.fillRect(x1, y1, dx, dy/2);
                g2.setColor(new Color(clr[i]));
                g2.fillRect(x1, y1+dy/2, dx, dy/2);
            }
            x1 += 60;
        }

        double r,f,sna,csa,e;
        int a,b,k;
        if(toch!=null){
            x=toch.x;
            y=toch.y;
            if(x>knp[0][0] && x<knp[0][0]+dx && y>knp[0][1] && y<knp[0][1]+dy){
                a=250;
                k=128;
                r=225.0f;
                f=0.1f;
                do{
                    r=a*Math.sin(k*f);
                    sna=Math.sin(f);
                    csa=Math.cos(f);
                    x2= (int) (r*csa);
                    y2= (int) (r*sna);
                    g2.setColor(new Color(rnd(1,255),rnd(1,255),rnd(1,255)));
                    g2.drawLine(cx,cy,cx+x2,cy+y2);
                    f+=0.25f;
                }while(f<=360.0f);
            }
            if(x>knp[1][0] && x<knp[1][0]+dx && y>knp[1][1] && y<knp[1][1]+dy){
                r=0;
                f=0.1f;
                do{
                    r+=0.3f;
                    sna=Math.sin(f);
                    csa=Math.cos(f);
                    x2= (int) (r*sna);
                    y2= (int) (r*csa);
                    g2.setColor(new Color(0x0032CD32));
                    g2.drawLine(cx,cy,cx+x2,cy+y2);
                    f+=0.35f;
                }while(f<=360.0f);
            }
            if(x>knp[2][0] && x<knp[2][0]+dx && y>knp[2][1] && y<knp[2][1]+dy){
                g2.setColor(new Color(0xEC00CE));
                r=200.0f;
                f=0;
                do{
                    sna=Math.sin(f);
                    csa=Math.cos(f);
                    x2= (int) (r*csa);
                    y2= (int) (r*sna);
                    g2.drawLine(cx,cy,cx+x2,cy+y2);
                    f+=0.5f;
                }while(f<=360.0f);
            }

            if(x>knp[3][0] && x<knp[3][0]+dx && y>knp[3][1] && y<knp[3][1]+dy){
                g2.setColor(new Color(0x00CC97));
                a=200;
                k=3;
                r=200.0f;
                f=0.1f;
                do{
                    sna=Math.sin(f);
                    csa=Math.cos(f);
                    r=a*Math.sin(k*f);
                    x2= (int) (r*csa);
                    y2= (int) (r*sna);
                    g2.drawLine(cx,cy,cx+x2,cy+y2);
                    f+=0.5f;
                }while(f<=360.0f);
            }

            if(x>knp[4][0] && x<knp[4][0]+dx && y>knp[4][1] && y<knp[4][1]+dy){
                g2.setColor(new Color(0x8B0679));
                a=200;
                k=5;
                r=200.0f;
                f=0.1f;
                do{
                    sna=Math.sin(f);
                    csa=Math.cos(f);
                    r=a*Math.sin(k*f);
                    x2= (int) (r*csa);
                    y2= (int) (r*sna);
                    g2.drawLine(cx,cy,cx+x2,cy+y2);
                    f+=0.5f;
                }while(f<=360.0f);
            }

            if(x>knp[5][0] && x<knp[5][0]+dx && y>knp[5][1] && y<knp[5][1]+dy){
                g2.setColor(new Color(0xED2873));
                a=200;
                k=128;
                r=200.0f;
                f=0.1f;
                do{
                    sna=Math.sin(f);
                    csa=Math.cos(f);
                    r=a*Math.sin(k*f);
                    x2= (int) (r*csa);
                    y2= (int) (r*sna);
                    g2.drawLine(cx,cy,cx+x2,cy+y2);
                    f+=0.5f;
                }while(f<=360.0f);
            }

            if(x>knp[6][0] && x<knp[6][0]+dx && y>knp[6][1] && y<knp[6][1]+dy){
                g2.setColor(new Color(0xFA613E));
                a=90;
                b=70;
                k=82;
                e=a/b;
                r=200.0f;
                f=0.0f;
                do{
                    x2= (int) ((b+e*b)*Math.cos(e*f)-k*Math.cos(f+e*f));
                    y2= (int) ((b+e*b)*Math.sin(e*f)-k*Math.sin(f+e*f));
                    g2.drawLine(cx,cy,cx+x2,cy+y2);
                    f+=0.2f;
                }while(f<=360.0f);
            }

            if(x>knp[7][0] && x<knp[7][0]+dx && y>knp[7][1] && y<knp[7][1]+dy){
                g2.setColor(new Color(0x351BFF));
                double Xmn;
                double Xmx;
                double x0,y0;
                Xmn=-3*PI;
                Xmx=3*PI;
                w=h=50;
                for(x0=Xmn;x0<=Xmx;x0+=0.05f)
                {
                    y0=-Math.sin(x0);
                    g2.fillRect((int)(w*x0+cx),(int)(h*y0+cy),5,5);
                }
                g2.setColor(new Color(0xFFF84A));
                for(x0=Xmn;x0<=Xmx;x0+=0.05f)
                {
                    y0=-Math.cos(x0);
                    g2.fillRect((int)(w*x0+cx),(int)(h*y0+cy),5,5);
                }
                wdk=1f;
                g2.setStroke(new BasicStroke(wdk));
                g2.setColor(new Color(0x000));
                g2.drawLine(minX,cy,maxX,cy);
                g2.drawLine(cx,minY+50,cx,maxY);

                String txt=null;
                txt="X";
                g2.drawLine(maxX,cy,maxX-15,cy-8);
                g2.drawLine(maxX,cy,maxX-15,cy+8);
                g.setFont(new Font("Trebuchet Ms", Font.BOLD, 24));
                g.setColor(new Color(0x060209));
                g2.drawString(txt,maxX-30,cy+30);

                txt="Y";
                g2.drawLine(cx,minY+50,cx-8,minY+15+50);
                g2.drawLine(cx,minY+50,cx+8,minY+15+50);
                g.setFont(new Font("Trebuchet Ms", Font.BOLD, 24));
                g.setColor(new Color(0x060209));
                g2.drawString(txt,cx+25,minY+50+30);

            }
        }
    }
    private static int rnd(int min, int max) {
        return (new Random()).ints(min,max).iterator().nextInt();
    }

    MouseAdapter mouseHandler= new MouseAdapter() {
        @Override
        public void mouseClicked(MouseEvent e) {
            super.mouseClicked(e);
            toch=e.getPoint();
            repaint();
        }
        @Override
        public void mouseMoved(MouseEvent e) {
            toch=e.getPoint();
        }
    };

    public WinGrLib() {
        super("Полярна система координат. Малюнки.");
        addWindowListener(this);

        addMouseMotionListener(mouseHandler);
        addMouseListener(mouseHandler);

        setLayout(null);
        setLocation(120, 100);
        setSize(1024, 600);
        show();
    }


}
