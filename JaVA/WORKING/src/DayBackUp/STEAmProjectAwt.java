import GUImgLib.GUImgLib;

import java.awt.*;
import java.io.FileWriter;
import java.io.IOException;

public class STEAmProjectAwt {

    public static void main(String[] args) throws Exception {

        try
        {
            FileWriter writer = new FileWriter("data.txt");
            String txt = "close";
            writer.write(txt);
            writer.flush();
            writer.close();
        } catch (IOException e) {
            e.printStackTrace();
        }

        new GUImgLib();
    }
}