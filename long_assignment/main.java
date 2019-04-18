import java.awt.SystemTray;
import java.util.*;
public class product{
    String category;
    String subcategory;
    String productName;
    int price;
    int units;
    public product(String subcategory,String productName,int price,int units){
        //this.category=category;
        this.subcategory=subcategory;
        this.producName=productName;
        this.price=price;
        this.units=units;
    }
    public void product_modify(int price,int units){
        this.price=price;
        this.units=units;
    }
    public void product_modify_price(int price){
        this.price=price;
    }
    public void product_modify_units(int units){
        this.units=units;
    }
}
private class database{
    //product[] prod_collection=new product[25];
    //List<product> product_list; //=new ArrayList<product>();
    Map<String, List<product>> databaseMap;// = new HashMap<>();


    public database(){
        databaseMap = new HashMap<>();
//product_list=new ArrayList<product>();
    }
    public insert(String subcategory,String productName){
        if(databaseMap.containsKey(subcategory)){
            productListInThatCategory=databaseMap.get(subcategory);
            int flag=0;
            for (int i = 0; i < productListInThatCategory.size(); i++) {
                if(productName.equals((productListInThatCategory.get(i)).productName)){
                    System.out.println("Error: The product is already present! You may have wanted to use modify functionality.");
                    flag=1;
                    break;
                }

            }
            
        }
    }

}