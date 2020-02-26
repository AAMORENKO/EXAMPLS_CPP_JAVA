public class NoNAME extends Frame implements WindowListener, MouseListener, MouseMotionListener {

    String mouseEvent=null;
    String mouseMoveEvent=null;
    String mouseDragEvent;
    String ctrl;
    public Point toch=null;
    public int x,y,w,h;

    public void windowOpened(WindowEvent e) {  };
    public void windowClosing(WindowEvent e) {
        dispose();
        System.exit(0);
    } ;
    public void windowClosed(WindowEvent e) {   };
    public void windowIconified(WindowEvent e) {   };
    public void windowDeiconified(WindowEvent e) {   };
    public void windowActivated(WindowEvent e) {   };
    public void windowDeactivated(WindowEvent e) {   };
    public void mouseClicked(MouseEvent e) {    };
    public void mousePressed(MouseEvent e) {   };
    public void mouseReleased(MouseEvent e) {   };
    public void mouseEntered(MouseEvent e) {   };
    public void mouseExited(MouseEvent e) {   };
    public void mouseDragged(MouseEvent e) {   };
    public void mouseMoved(MouseEvent e) {   };


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

        int x1, y1, x2, y2,x3,y3;

        Graphics2D g2 = (Graphics2D) g;
        g2.setStroke(new BasicStroke(1.0f));

        cx = Math.abs(maxX - minX) / 2;
        cy = Math.abs(maxY - minY) / 2;
        dx = maxX / 10;
        dy = maxY / 10;

	// TODO THIS PAINT

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

    public NoNAME() {
        super("Визначні дати");
        addWindowListener(this);

        addMouseMotionListener(mouseHandler);
        addMouseListener(mouseHandler);

        setLayout(null);
        setLocation(120, 100);
        setSize(1024, 600);
        show();
    }
}

--------------------------------------------------------------------------

        GregorianCalendar calendar = new GregorianCalendar();
        int year = calendar.get(Calendar.YEAR);
        int month = calendar.get(Calendar.MONTH)+1;
        int day = calendar.get(Calendar.DAY_OF_MONTH);

	String txt = "Сьогодні: ";
	txt += " " + day + " ";
        switch (month) {
            case 1:
                txt += "січня ";
                break;
        }
        txt += year + " року";
        g.setFont(new Font("Trebuchet Ms", Font.BOLD, 24));
        g.setColor(new Color(0x2728CB));
        g.drawString(txt, 40, 70);

----------------------------------------------------------------------------------------
        Dimension rc = getSize();
        Insets in = getInsets();

        int RH = rc.width;
        int RW = rc.height;

        int minX = in.left;
        int maxX = RH - in.right;
        int minY = in.top;
        int maxY = RW - in.bottom;

        int cx, cy, dx, dy;

        cx = Math.abs(maxX - minX) / 2;
        cy = Math.abs(maxY - minY) / 2;
        dx = maxX / 10;
        dy = maxY / 10;

----------------------------------------------------------------------------------------

        int x1, y1, x2, y2;
        int cr,cq,cb;
        int d;

        float wdk=3.0f;

        Graphics2D g2 = (Graphics2D) g;
        g2.setStroke(new BasicStroke(wdk));

----------------------------------------------------------------------------------------

        for (int i = 0; i <100000 ; i++) {
            cr = rnd(0, 255);
            cq = rnd(0, 255);
            cb = rnd(0, 255);
            g.setColor(new Color(cr, cq, cb));

            x1 = rnd(minX+50, maxX-150);
            y1 = rnd(minY+50, maxY-150);
            d = rnd(50, 100);
            g.fillOval(x1, y1, d, d);

            cr = rnd(0, 255);
            cq = rnd(0, 255);
            cb = rnd(0, 255);
            g.setColor(new Color(cr, cq, cb));

            x1 = rnd(minX+50, maxX-150);
            y1 = rnd(minY+50, maxY-150);
            d = rnd(50, 100);
            g.fillRect(x1, y1, d, d);
        }
----------------------------------------------------------------------------------------
	import java.util.Random;

  	Random rn = new Random();
        int randomNum = rn.nextInt((max - min) + 1) + min;

----------------------------------------------------------------------------------------

        private static int rnd(int min, int max) {
            return (new Random()).ints(min,max).iterator().nextInt();
        }

----------------------------------------------------------------------------------------
    private static  int rnd(int min, int max) {
        max -= min;
        return (int) (Math.random() * +max) + min;
        int r = (new Random()).ints(5,67).iterator().nextInt();
        return  (new Random()).ints(min,max).iterator().nextInt();
    }
----------------------------------------------------------------------------------------

        GregorianCalendar calendar = new GregorianCalendar(2017, Calendar.JANUARY , 25);
        calendar.set(Calendar.HOUR, 10);
        calendar.set(Calendar.MINUTE, 42);
        calendar.set(Calendar.SECOND, 12);

        System.out.println("Год: " + calendar.get(Calendar.YEAR));
        System.out.println("Месяц: " + calendar.get(Calendar.MONTH));
        System.out.println("Порядковый номер недели в месяце: " + calendar.get(Calendar.WEEK_OF_MONTH));//порядковый номер недели в месяце

        System.out.println("Число: " + calendar.get(Calendar.DAY_OF_MONTH));

        System.out.println("Часы: " + calendar.get(Calendar.HOUR));
        System.out.println("Минуты: " + calendar.get(Calendar.MINUTE));
        System.out.println("Секунды: " + calendar.get(Calendar.SECOND));
        System.out.println("Миллисекунды: " + calendar.get(Calendar.MILLISECOND));

--------------------------------------------------------------------------------------------------

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

            cx = Math.abs(maxX - minX) / 2;
            cy = Math.abs(maxY - minY) / 2;
            dx = maxX / 10;
            dy = maxY / 10;

            g.setColor(new Color(0x430486));
            String txt = "Програмування графічними примітивами: ";
            g.setFont(new Font("Times New Roman", Font.BOLD, 24));
            g.drawString(txt, 20, 80);


            int x1, y1, x2, y2;

            Graphics2D g2 = (Graphics2D) g;
            g2.setStroke(new BasicStroke(3.0f));


            // TO DO

            x1 = 120;
            y1 = 80;
            int d = 500;
            dx = dy = 18;
            g.setColor(new Color(0x103610));
            for (int i = 0; i < 19; i++) {
                g.drawRect(x1, y1, d, d);
                x1 += dx;
                y1 += dy;
                d -= 2 * dx;
            }


        }

        public NoNames() {
            super("Графічні примітиви.");
            addWindowListener(this);
            setLayout(null);
            setLocation(120,100);
            setSize(800,600);
           show();
        }
    }

--------------------------------------------------------------------------------------------------

            final double pi = 3.1415926535897932384626433832795;

            double xf, yf, f;
            f = 0;
            int D = 500;
            int n = 15;
            int k = 0;

            int[] XA = new int[360];
            int[] YA = new int[360];

            while (k <= n) {
                xf = D / 2 * Math.cos(f);
                yf = D / 2 * Math.sin(f);
                x1 = (int) xf + cx;
                y1 = (int) yf + cy + 30;
                XA[k] = x1;
                YA[k] = y1;
                k++;
                f += (2 * pi / n);
                xf = D / 2 * Math.cos(f);
                yf = D / 2 * Math.sin(f);
                x2 = (int) xf + cx;
                y2 = (int) yf + cy + 30;
                XA[k] = x2;
                YA[k] = y2;
                //g.drawLine(x1,y1,x2,y2);
                //k++;
            }

            for (k = 0; k < n; k++) {
                for (int j = k + 1; j < n; j++) {
                    wdk = (float) rnd(2, 8);
                    g2.setStroke(new BasicStroke(wdk));
                    g.setColor(new Color(rnd(1, 255), rnd(1, 255), rnd(1, 255)));
                    g.drawLine(XA[k], YA[k], XA[j], YA[j]);

                    try {
                        sleep(5);
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }
                }

            }
 --------------------------------------------------------------------------------------------------

//  Повна версія - додані - Змійка Спіраль Телетайп
//  --------------- MovingObjectMatrix

import GrMovingObject.GrMovingObject;

import java.awt.*;

public class MovingObjectMatrix {

    public static void main(String[] args) {

        new GrMovingObject();
    }
}

// ------------------- GrMovingObject

package GrMovingObject;

import java.awt.*;
import java.awt.event.*;

import static java.lang.Thread.sleep;


public class GrMovingObject extends Frame implements WindowListener {

    public void windowOpened(WindowEvent e) {};

    public void windowClosing(WindowEvent e) {
        dispose();
        System.exit(0);
    };

    public void windowClosed(WindowEvent e) {};
    public void windowIconified(WindowEvent e) {};
    public void windowDeiconified(WindowEvent e) {};
    public void windowActivated(WindowEvent e) {};
    public void windowDeactivated(WindowEvent e) {};

    public void paint(Graphics g) {

        Dimension rc = getSize();
        Insets in = getInsets();

        int RH = rc.width;
        int RW = rc.height;

        int minX = in.left;
        int maxX = RH - in.right;
        int minY = in.top;
        int maxY = RW - in.bottom;
        int x1, y1, x2, y2;
        int cr,cq,cb;
        int d;
        int cx, cy, dx, dy;
        int bx,ex,by,ey;

        float wdk=3.0f;

        cx = Math.abs(maxX - minX) / 2;
        cy = Math.abs(maxY - minY) / 2;
        dx = maxX / 10;
        dy = maxY / 10;

        Graphics2D g2 = (Graphics2D) g;
        g2.setStroke(new BasicStroke(wdk));


        // TO DO

        int mtime=25;

        g.setColor(new Color(0,0,0));
        g.fillRect(minX,minY,maxX,maxY);

        g.setColor(new Color(255, 177, 30));
        d=600;
        x1=cx-dx*4+20;
        y1=cy-4*dy;
        x2=x1+d;
        y2=y1+d-30;
        g.drawRect(x1,y1,x2,y2);

        bx=x1+dx/2;
        ex=x2-10;
        by=y1+10;
        ey=y2-10;

        //g.drawRect(bx,by,ex,ey);
        dx=dy=45;

        for (int i = 0; i <1 ; i++) {
            x1 = bx;
            y1 = by;
            while (x1 <= ex + dx) {
                g.setColor(new Color(255, 177, 30));
                g.fillRect(x1, y1, dx, dy);
                try {
                    sleep(mtime);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
                g.setColor(new Color(0, 0, 0));
                g.fillRect(x1, y1, dx, dy);
                //g.setColor(new Color(154, 15, 255));
                g.drawRect(x1, y1, dx, dy);
                x1 += dx;
                //y1+=dy;
            }

            x1 = ex + dx;
            y1 = by;
            while (y1 <= ey) {
                g.setColor(new Color(255, 177, 30));
                g.fillRect(x1, y1, dx, dy);
                try {
                    sleep(mtime);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
                g.setColor(new Color(0, 0, 0));
                g.fillRect(x1, y1, dx, dy);
                //g.setColor(new Color(154, 15, 255));
                g.drawRect(x1, y1, dx, dy);
                //x1+=dx;
                y1 += dy;
            }

            x1 = ex;
            y1 = ey;
            while (x1 > bx) {
                g.setColor(new Color(255, 177, 30));
                g.fillRect(x1, y1, dx, dy);
                try {
                    sleep(mtime);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
                g.setColor(new Color(0, 0, 0));
                g.fillRect(x1, y1, dx, dy);
                //g.setColor(new Color(154, 15, 255));
                g.drawRect(x1, y1, dx, dy);

                x1 -= dx;
                //y1+=dy;
            }

            x1 = bx;
            y1 = ey;
            while (y1 >= by) {
                g.setColor(new Color(255, 177, 30));
                g.fillRect(x1, y1, dx, dy);
                try {
                    sleep(mtime);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
                g.setColor(new Color(0, 0, 0));
                g.fillRect(x1, y1, dx, dy);
                //g.setColor(new Color(154, 15, 255));
                g.drawRect(x1, y1, dx, dy);
                //x1+=dx;
                y1 -= dy;
            }

            x1 = bx;
            y1 = by;
            while (x1 <= ex) {
                g.setColor(new Color(255, 177, 30));
                g.fillRect(x1, y1, dx, dy);
                try {
                    sleep(mtime);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
                g.setColor(new Color(0, 0, 0));
                g.fillRect(x1, y1, dx, dy);
                //g.setColor(new Color(154, 15, 255));
                g.drawRect(x1, y1, dx, dy);
                x1 += dx;
                y1 += dy;
            }

            x1 = ex;
            y1 = ey;
            while (x1 > bx) {
                g.setColor(new Color(255, 177, 30));
                g.fillRect(x1, y1, dx, dy);
                try {
                    sleep(mtime);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
                g.setColor(new Color(0, 0, 0));
                g.fillRect(x1, y1, dx, dy);
                //g.setColor(new Color(154, 15, 255));
                g.drawRect(x1, y1, dx, dy);

                x1 -= dx;
                //y1+=dy;
            }

            x1 = bx;
            y1 = ey;
            while (x1 <= ex) {
                g.setColor(new Color(255, 177, 30));
                g.fillRect(x1, y1, dx, dy);
                try {
                    sleep(mtime);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
                g.setColor(new Color(0, 0, 0));
                g.fillRect(x1, y1, dx, dy);
                //g.setColor(new Color(154, 15, 255));
                g.drawRect(x1, y1, dx, dy);
                x1 += dx;
                y1 -= dy;
            }

            x1 = ex;
            y1 = by;
            while (x1 > bx) {
                g.setColor(new Color(255, 177, 30));
                g.fillRect(x1, y1, dx, dy);
                try {
                    sleep(mtime);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
                g.setColor(new Color(0, 0, 0));
                g.fillRect(x1, y1, dx, dy);
                //g.setColor(new Color(154, 15, 255));
                g.drawRect(x1, y1, dx, dy);

                x1 -= dx;
                //y1+=dy;
            }
        }


   //-------------------------------------------------------

        y1=by+dy/2;

        while(y1<ey)
        {
            x1 = bx;
            while (x1 <= ex + dx) {
                g.setColor(new Color(255, 177, 30));
                g.fillRect(x1, y1, dx, dy);
                try {
                    sleep(mtime);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
                g.setColor(new Color(0, 0, 0));
                g.fillRect(x1, y1, dx, dy);
                //g.setColor(new Color(154, 15, 255));
                g.drawRect(x1, y1, dx, dy);
                x1 += dx;
                //y1+=dy;
            }
            x1 = ex;
            y1 +=dy;
            while (x1 > bx) {
                g.setColor(new Color(255, 177, 30));
                g.fillRect(x1, y1, dx, dy);
                try {
                    sleep(mtime);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
                g.setColor(new Color(0, 0, 0));
                g.fillRect(x1, y1, dx, dy);
                //g.setColor(new Color(154, 15, 255));
                g.drawRect(x1, y1, dx, dy);

                x1 -= dx;
                //y1+=dy;
            }
            y1+=dy;
        }
//---------------------------------------------------------

        int nx=bx;
        int kx=ex;
        int ny=by;
        int ky=ey;


        x1=bx;
        while(x1<=(nx+kx)/2) {
            x1 = bx;
            y1 = by;
            while (x1 <= ex + dx) {
                g.setColor(new Color(255, 177, 30));
                g.fillRect(x1, y1, dx, dy);
                try {
                    sleep(mtime);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
                g.setColor(new Color(0, 0, 0));
                g.fillRect(x1, y1, dx, dy);
                //g.setColor(new Color(154, 15, 255));
                g.drawRect(x1, y1, dx, dy);
                x1 += dx;
                //y1+=dy;
            }

            x1 = ex + dx;
            y1 = by;
            while (y1 <= ey) {
                g.setColor(new Color(255, 177, 30));
                g.fillRect(x1, y1, dx, dy);
                try {
                    sleep(mtime);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
                g.setColor(new Color(0, 0, 0));
                g.fillRect(x1, y1, dx, dy);
                //g.setColor(new Color(154, 15, 255));
                g.drawRect(x1, y1, dx, dy);
                //x1+=dx;
                y1 += dy;
            }

            x1 = ex;
            y1 = ey;
            while (x1 > bx) {
                g.setColor(new Color(255, 177, 30));
                g.fillRect(x1, y1, dx, dy);
                try {
                    sleep(mtime);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
                g.setColor(new Color(0, 0, 0));
                g.fillRect(x1, y1, dx, dy);
                //g.setColor(new Color(154, 15, 255));
                g.drawRect(x1, y1, dx, dy);

                x1 -= dx;
                //y1+=dy;
            }

            x1 = bx;
            y1 = ey;
            while (y1 > by + dy) {
                g.setColor(new Color(255, 177, 30));
                g.fillRect(x1, y1, dx, dy);
                try {
                    sleep(mtime);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
                g.setColor(new Color(0, 0, 0));
                g.fillRect(x1, y1, dx, dy);
                //g.setColor(new Color(154, 15, 255));
                g.drawRect(x1, y1, dx, dy);
                //x1+=dx;
                y1 -= dy;
            }

            bx+=dx; ex-=dx;
            by+=dy;ey-=dy;

        }

 //----------------------------------------------

        String z;
        String txt = "Я вивчаю мову програмування JAVA";

        z="";
        g.setFont(new Font("Trebuchet Ms", Font.BOLD, 28));

        x1=cx-300; y1=cy+40; d=20;

        for(char ch : txt.toCharArray()){
            z+=ch;
            g.setColor(new Color(255,255,255));
            g.fillRect(x1,y1-d*2,d,d*3);
            g.setColor(new Color(0,0,0));
            g.drawString(z, x1, y1);


            try {
                sleep(mtime+80);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }

            g.setColor(new Color(0, 0, 0));
            g.fillRect(x1,y1-d*2,d,d*3);
            g.setColor(new Color(255,255,255));
            g.drawString(z, x1, y1);


            x1+=d;
            z="";

        }



    }

    public GrMovingObject() {
        super("Рухомі об'єкти");
        addWindowListener(this);
        setLayout(null);
        setLocation(100,20);
        setSize(900,700);
        show();
    }
}


/*

Найбiльше i найдорожче добро кожного народу – це його мова, та жива схованка людського духу, його багата скарбниця, в яку народ складає і своє авнє життя i своi сподiванки, розум, досвiд, почування.
Запашна, співуча, гнучка, милозвучна, сповнена музики і квіткових пахощів – скількома епітетами супроводяться визнання української мови.
Мова – втілення думки. Що багатша думка, то багатша мова. Любімо її, вивчаймо її, розвиваймо її! Борімося за красу мови, за правильність мови, за приступність мови, за багатство мови.
Народ, що не усвідомлює значення рідної мови для свого вищого духовного життя і сам її покидає й відрікається, виконує над собою самовбивство.

*/
