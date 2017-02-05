
import java.util.Scanner;
import java.lang.Math;
import java.text.DecimalFormat;

class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int num = sc.nextInt();
        int[][] XCords = new int[num][];
        int[][] YCords = new int[num][];
        
        for (int i=0; i < num; i++) {
            
            int numCords = sc.nextInt();
            
            XCords[i] = new int[numCords];
            YCords[i] = new int[numCords];
            
            for(int j=0; j < numCords; j++) {
                XCords[i][j] = sc.nextInt();
                YCords[i][j] = sc.nextInt();
            }
            
            double minDist = Math.sqrt(Math.pow(YCords[i][0] - YCords[i][1], 2.0) + Math.pow(XCords[i][0] - XCords[i][1], 2.0));
            //System.out.println(minDist);
            int pointA = 0, pointB = 1;
            
            for(int k=0; k < numCords; k++) {
                for(int l=0; l < numCords; l++) {
                    if(k != l) {
                        double distance = Math.sqrt(Math.pow(YCords[i][k] - YCords[i][l], 2.0) + Math.pow(XCords[i][k] - XCords[i][l], 2.0));
                        //System.out.println(distance);
                        if(distance < minDist) {
                            minDist = distance;
                            pointA = k;
                            pointB = l;
                        }
                    }
                }
            }
            //System.out.println(pointA + " " + pointB);
            double beautyPointX = (XCords[i][pointA] + XCords[i][pointB])/2.0;
            double beautyPointY = (YCords[i][pointA] + YCords[i][pointB])/2.0;
            //System.out.println(beautyPointX + " " + beautyPointY);
            
            DecimalFormat df = new DecimalFormat("####0.000");
            System.out.println(df.format(beautyPointX) + " " + df.format(beautyPointY) + "\n");
       
        }
    }
    
}
