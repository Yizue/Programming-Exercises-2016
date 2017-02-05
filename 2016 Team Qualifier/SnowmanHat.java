
import java.util.Scanner;
import java.text.DecimalFormat;

public class SnowmanHat {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int testNum = sc.nextInt();
        
        DecimalFormat df = new DecimalFormat("#0.00");
        
        for (int i=0; i<testNum; i++) {
            double rad = sc.nextDouble();
            double height = sc.nextDouble();
            
            double sideRad = Math.sqrt( Math.pow(height + rad, 2.0) - Math.pow(rad, 2.0) );
            
            double halfChord = rad * sideRad / (rad+height);
            
            double hatHeight = Math.sqrt( Math.pow(sideRad, 2.0) - Math.pow(halfChord, 2.0) );
            
            double area = hatHeight*halfChord;
            
            System.out.println(df.format(area));
        }
        
    }
    
}
