public class OS4 {
    public static long Func(int i){
        if(i==0) return 0;
        int b=3,c=3;
        long a=0;
        for(int j=0;j<100000000;j++){
            a+=2*b+c-i;
        }
        return a+Func(i-1);
    }
    public static void main(String[] args) {
        double time=System.currentTimeMillis();
        System.out.println(Func(5));
        System.out.println("Время выполнения программы "+(System.currentTimeMillis()-time)+" миллисекунды");
    }
}
