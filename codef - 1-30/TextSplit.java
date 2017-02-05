import java.util.Scanner;

public class TextSplit {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int n = sc.nextInt(); 
        int p = sc.nextInt();
        int q = sc.nextInt();
        
        String s = sc.next();
        
        int spCount = -1;
        
        boolean found = false;
        int pC = 0, qC = 0;
        
        
        for (int i=0; i<=100; i++) {
            for (int j=0; j<=100; j++) {
                if( (n - (i*p+j*q)) == 0 ) {
                    pC = i;
                    qC = j;
                    found = true;
                    break;
                } 
            }
        }
        
        int strP = 0;
        
        if (found) {
            spCount =  pC + qC;
            System.out.println(spCount);
            
            for (int k = 0; k < pC; k++) {
                System.out.println(s.substring(k*p, k*p + p));
                strP += p;
            }
            
            for (int l = 0; l < qC; l++) {
                System.out.println(s.substring(l*q + strP, l*q + q + strP));
            }
            
        }
        else {
            System.out.println(spCount);
        }
    }
    
}
