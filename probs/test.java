/*
  SRM 537 DIV1 500
*/
import java.util.Scanner;

public class test {

    static int MAXN = 102;

    boolean [][] w = new boolean [ MAXN ][ MAXN ];
    int [][] val = new int [ MAXN ][ MAXN ]; 
    int cnt , sum;

    public void dfs()
    {
        do{

        }while( front < node);
    }

    public static double expectedNumber(int[] d, int[] s1, int[] s2, int k )
    {
        int n = d.size();

        for( int i = 0 ; i < n ; ++ i )
            {
                w[ i ][ s2[ i ] ] = true;
                w[ s2[ i ] ][ i ] = true;
                
            }

        dfs( );

        return double( sum / cnt ); 
    }

    public static void main( String[] args )
    {
        BigInteger a , b;
        //Scanner in = new Scanner( System.in );
        a = System.in.nextInt();
        b = System.in.nextInt();

        System.out.println( a + b );
    }
}