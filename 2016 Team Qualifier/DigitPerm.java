
import java.util.Scanner;

public class DigitPerm {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int testNum = sc.nextInt();
        
        for (int i=0; i<testNum; i++) {
            int digitNum = sc.nextInt();
            String hexNum = sc.next();
            
            int[] numCount = new int[16];
            for(int a=0; a<16; a++){
                numCount[a] = 0;
            }
            
            for(int j=0; j<digitNum; j++) {
                char digit = hexNum.charAt(j);
                switch (digit){
                    case '1':
                        numCount[0]++;
                        break;
                    case '2':
                        numCount[1]++;
                        break;
                    case '3':
                        numCount[2]++;
                        break;
                    case '4':
                        numCount[3]++;
                        break;
                    case '5':
                        numCount[4]++;
                        break;
                    case '6':
                        numCount[5]++;
                        break;
                    case '7':
                        numCount[6]++;
                        break;
                    case '8':
                        numCount[7]++;
                        break;
                    case '9':
                        numCount[8]++;
                        break;
                    case 'A':
                        numCount[9]++;
                        break;
                    case 'B':
                        numCount[10]++;
                        break;
                    case 'C':
                        numCount[11]++;
                        break;
                    case 'D':
                        numCount[12]++;
                        break;
                    case 'E':
                        numCount[13]++;
                        break;
                    case 'F':
                        numCount[14]++;
                        break;
                    case '0':
                        numCount[15]++;
                        break;
                }          
            }
            
            long uniqueP, uniqueDenom = 1, uniqueDenomZero = 1;
            
            if (numCount[15] == 0) {
                for (int b=0; b<16; b++){
                    uniqueDenom *= fact(numCount[b]);
                }
                uniqueP = fact(digitNum) / uniqueDenom;
            }
            else {
                for (int b=0; b<16; b++){
                    uniqueDenom *= fact(numCount[b]);
                    if(b!=15)
                        uniqueDenomZero *= fact(numCount[b]);
                    else
                       uniqueDenomZero *= fact(numCount[b]-1); 
                }
                
                uniqueP = (fact(digitNum) / uniqueDenom) - (fact(digitNum-1) / uniqueDenomZero);
            }
            
            System.out.println(uniqueP);
        }
    }
    
    public static long fact(int n) {
        long f = 1;
        for (int i = 1; i <= n; i++) {
            f *= i;
        }
        return f;
    }
    
}
