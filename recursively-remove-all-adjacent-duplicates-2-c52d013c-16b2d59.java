
import java.util.*;

class TestClass {
    ArrayList<Character> list;
    TestClass()
    {
        list=new ArrayList<Character>();
    }
    void deleteAdjacent(int iterator,char val) throws Exception
    {
        if(iterator<this.list.size()-1)
        if(val==list.get(iterator))
        {
            this.list.remove(iterator);
            this.deleteAdjacent(iterator,val);
        }
    }
    void removeDup(int iterator,char old) throws Exception
        {
            if(iterator<this.list.size()-1)
            {
                if(old==list.get(iterator))
                {
                    this.deleteAdjacent(iterator-1,old);
                    old=list.get(iterator-1);
                    this.removeDup(iterator,old);
                }
                else
                {
                    old=list.get(iterator);
                    this.removeDup(++iterator,old);
                }
                
            }
            
        }
    public static void main(String args[] ) throws Exception {
    
        Scanner sc = new Scanner(System.in);
        TestClass obj=new TestClass();
        int test=Integer.parseInt(sc.nextLine());
        while(test-->0)
        {
            String userString=sc.nextLine();
            obj.list.clear();
            for(int i=0;i<userString.length();i++)
            {
                obj.list.add(userString.charAt(i));
            }
            obj.removeDup(1,obj.list.get(0));
            for(int i=0;i<obj.list.size();i++)
            {
                System.out.print(obj.list.get(i));
            }
            System.out.println();
            
        }
    }
}
