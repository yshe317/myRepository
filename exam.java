import java.util.LinkedList;
import java.util.List;
interface Sort{         
    void print_increasing_order(List<Covid19> ls);
}
public class Tool{        
    public static void print_tool(List<Covid19> ls) {
        Sort s = new Sort(){                             
            public void print_increasing_order(List<Covid19> ls){                                           
                //sort the convid 19                                           
                List<Covid19> sortedls = new LinkedList<>(Covid19);                                            
                while(ls.size()!= 0) {                                                      
                    int mini = ls.get(0).getCases();                                                    
                    int index = 0;                                                       
                    for(int i = 0; i<ls.size();i++) {                                                                    
                        if(ls.get(i). getCases()  < mini) {                                                                       
                            index = i;                                                                     
                            mini =  ls.get(i). getCases();                                                                               
                        }                                                                                                        
                    }                                                   
                    sortedls.add(ls.remove(index));                                           
                }                                            
                // print                                       
                for(int i = 0;i<sortedls.size();i++) {                                                    
                    System.out.println(  sortedls.get(i).getCountryName() );                                                                              
                }                               
            }                  
        };          
        s. print_increasing_order(ls);         
    }
    public static void main(String[] s) {
        .out.print("ss\n");
    }
}
