
import java.util.Scanner;


public class OddManOut {

    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int tNum = sc.nextInt();
        
        for (int i=0; i<tNum; i++) {
            int gNum = sc.nextInt();
            int[] arr = new int[gNum];
            
            for (int j=0; j<gNum; j++) {
                arr[j] = sc.nextInt();
            }
            
            int oddNum;
            boolean pairFound = false;
            int oddOne = arr[0];
            
            for(int l=0; l< gNum; l++) {
                
                oddNum = arr[l];
                pairFound = false;
                    
                for(int k = 0; k< gNum ; k++) {
                    if(oddNum == arr[k] && k != l) {
                        pairFound = true;
                    }
                }
                
                if(pairFound == false) {
                    oddOne = arr[l];
                    break;
                }
            }
            
            System.out.println("Case #" + (i+1) + ": " + oddOne);
        }
    }
    
}
