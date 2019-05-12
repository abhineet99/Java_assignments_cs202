import org.junit.Assert;
import org.junit.Before;
import org.junit.Test;

//import jdk.internal.jline.internal.TestAccessible;

import static org.junit.Assert.assertNotNull;
import java.awt.SystemTray;
import java.util.*;
import java.io.*;
import java.nio.file.*;
import java.nio.charset.*;
//import jdk.internal.jline.internal.TestAccessible;

//import org.graalvm.compiler.lir.LIRInstruction.Temp;

public class testClass{
    database myDatabase;
    @Before
    public void init(){
        myDatabase=new database();
    }
    @Test
    public void testProductAtSamePath(){
        System.out.println("\nTesting testProductAtSamePath........");
        product myProduct=new product("samsung>phone", "s8", 23, 23);
        myDatabase.insert(myProduct);
        product myProduct1=new product("samsung>phone", "s8", 23, 23);
        //inserting the same phone again
        myDatabase.insert(myProduct1);
        //assertNotNull(myProduct1);

    }
    @Test
    public void deleteProductWhichDoesNotExist(){
        System.out.println("\nTesting deleteProductWhichDoesNotExist........");
        myDatabase.delete("abrakadabra");
        
    }
    @Test
    public void searchProductWhichDoesNotExist(){
        System.out.println("\nTesting searchProductWhichDoesNotExist........");
         myDatabase.search("abracadabra");
    }
    @Test
    public void addToCartOutOfStockProduct(){
        System.out.println("\nTesting addToCartOutOfStockProduct........");
        product myProduct1=new product("samsung>phone", "s9", 0, 0);
        //note that zero quantity is added
        myDatabase.insert(myProduct1);
        customer myCustomer=new customer("test", 999);
        myCustomer.addToCart(myProduct1, 1);
        
    }
    @Test
    public void checkOutCartWhenOutOfFunds(){
        System.out.println("\nTesting checkOutCartWhenOutOfFunds........");
        product myProduct1=new product("samsung>phone", "s10", 1000, 10000);
        myDatabase.insert(myProduct1);
        customer myCustomer=new customer("test", 1);
        myCustomer.addToCart(myProduct1, 1);    
        myCustomer.checkoutCart(myDatabase);

    }
    @Test
    public void testSerializationDatabase() throws IOException{
        product myProduct=new product("samsung>phone", "s8", 23, 23);

        myDatabase.insert(myProduct);
        //product testProduc1t=myDatabase.search("s8");
        System.out.println("\nDatabase serialization test.......");
        File file = new File("databasetest.csv"); 
        file.delete();
        final Path path = Paths.get("databasetest.csv");
       Iterator<Map.Entry<String, List<product>>> it= myDatabase.databaseMap.entrySet().iterator();
        while (it.hasNext()) {
            Map.Entry<String, List<product>> pair = (Map.Entry<String, List<product>>)it.next();
            List<product> productList =pair.getValue();
            for (int i = 0; i < productList.size(); i++) {
                product productToBeWritten=productList.get(i);
                String toWriteToDatabaseFile=productToBeWritten.getSubcategory()+","+productToBeWritten.getProductName()+","+productToBeWritten.getPrice()+","+productToBeWritten.getUnits();
                Files.write(path, Arrays.asList(toWriteToDatabaseFile), StandardCharsets.UTF_8,
            Files.exists(path) ? StandardOpenOption.APPEND : StandardOpenOption.CREATE);
            it.remove(); // avoids a ConcurrentModificationException
            }
        }
        database myDatabase1=new database();
        //customer myCustomer=new customer("false", 0);
        BufferedReader bro = null;
        String strLine = "";
        try {
            bro = new BufferedReader( new FileReader("databasetest.csv"));
            while( (strLine = bro.readLine()) != null){
                String[] databaseData=strLine.split(",");
                product productToBeAddedFromFile=new product(databaseData[0],databaseData[1],Integer.parseInt(databaseData[2]),Integer.parseInt(databaseData[3]));
                myDatabase1.insert(productToBeAddedFromFile);
            }
        } catch (FileNotFoundException e) {
            System.err.println("Seems like no database file already exists, will create a new database!");
        } catch (IOException e) {
            System.err.println("Unable to read database file!");
        }
        product testProduct=myDatabase1.search("s8");
        if(testProduct.getPrice()==23) //matched a random attribute of a product
        System.out.println("Serialization test for database complete");
        else
        System.out.println("Serialization test for database failed");
    }  
    @Test 
    public void testSerializationCustomerCart() throws IOException{
        System.out.println("\nCustomer Cart serialization test.......");
        product myProduct=new product("Apple", "iPhone", 90000, 2);
        customer myCustomer=new customer("naya", 100000);
        myCustomer.addToCart(myProduct, 2);
        List<customer> customerList=new ArrayList<customer>();
        customerList.add(myCustomer);
        File file= new File("customertest.csv");
        file.delete();
        final Path path1= Paths.get("customertest.csv");
        for (int i = 0; i < customerList.size(); i++) {
            
            customer customerToBeWritten=customerList.get(i);
            String toWriteToDatabaseFile=customerToBeWritten.getCustomerID()+","+customerToBeWritten.getRemainingFunds()+","+customerToBeWritten.cart.size();
            for (int j = 0; j < customerToBeWritten.cart.size(); j++) {
                toWriteToDatabaseFile+=","+customerToBeWritten.cart.get(i).getL().getProductName()+","+customerToBeWritten.cart.get(i).getR();

            }
        Files.write(path1, Arrays.asList(toWriteToDatabaseFile), StandardCharsets.UTF_8,
            Files.exists(path1) ? StandardOpenOption.APPEND : StandardOpenOption.CREATE);
        }
        String strLine = "";

        List<customer> customerList1=new ArrayList<customer>();
        try {
            BufferedReader bro = new BufferedReader( new FileReader("customertest.csv"));
            while( (strLine = bro.readLine()) != null){
                String[] customerData=strLine.split(",");
                customer customerToBeAddedFromFile=new customer(customerData[0],Integer.parseInt(customerData[1]));
                int customerCartSize=Integer.parseInt(customerData[2]);
                for(int i=0;i<customerCartSize;i++){
                    String productName=customerData[2*i+3];
                    int quantityDemanded=Integer.parseInt(customerData[2*i+4]);
                    // product productToBeAddedToCart=myDatabase.search(productName);
                    // if(productToBeAddedToCart.productName.equals("false")){
                    //     System.out.println("Some of the products in customers' cart have been removed from database, they will be removed from customers' cart automatically,product: "+productName);

                    // }
                    product productToBeAddedToCart=new product("doesntMatter", productName,12, 12);
                    //else{
                        Pair<product,Integer> pair= new Pair<product,Integer>(productToBeAddedToCart,quantityDemanded);
                        //if(quantityDemanded<=productToBeAddedToCart.units){
                            customerToBeAddedFromFile.cart.add(pair);
                            //System.out.println("Success, product added to your cart!");
                        //}
                        //else
                        //System.out.println("Some products have been removed from customer "+customerToBeAddedFromFile.customerID +"'s " +"cart because of unavailability!");
                        //customerToBeAddedFromFile.cart.add(pair);
                    //}
                }
                customerList1.add(customerToBeAddedFromFile);
            }
        } catch (FileNotFoundException e) {
            System.err.println("Seems like no database file already exists, will create a new database!");
        } catch (IOException e) {
            System.err.println("Unable to read database file!");
        }    
        if(customerList.get(0).cart.get(0).getL().getProductName().equals(customerList1.get(0).cart.get(0).getL().getProductName()))
        System.out.println("Serialization test for customer Cart complete");
        else
        System.out.println("Serialization test for customer Cart failed");


    
    }

}