// 1) Download mongoDB connector
// Jar File Link : // Jar File Link : https://jar-download.com/artifacts/org.mongodb/mongo-java-driver/3.10.1/source-code
// 2) On Ecplise Create Java Project
// 3) Add a package mongodbConnectivity in project
// 4) Add Class Connectivity in package
// 5) Paste Below Code.

package mongodbConnectivity;
import java.util.*;
import com.mongodb.MongoClient;
import com.mongodb.DB;
import com.mongodb.DBCollection;
import com.mongodb.DBCursor;
import com.mongodb.BasicDBObject;

public class Connectivity {
 
    public static void main(String[] args) {
        try {
            MongoClient mongoClient = new MongoClient("10.10.10.108", 27017);
            String dbName = "te31410_db";
            System.out.println("Database: " + dbName);
            String collectionname = "Students";
            System.out.println("Collection name : Students");
            DB db = mongoClient.getDB(dbName);
            DBCollection collection = db.getCollection(collectionname);
            Scanner sc = new Scanner(System.in);
            int opt = 0;
            while(opt!=5)
            {
            	System.out.println("------MENU------");
            	System.out.println("1. Insert in collection");
            	System.out.println("2. Read from collection");
            	System.out.println("3. Update in collection");
            	System.out.println("4. Delete from collection");
            	System.out.println("5. EXIT");
            	opt = sc.nextInt();
            	if(opt==1)
            	{
            		System.out.println("Enter the roll no of student : ");
            		int rol = sc.nextInt();
            		System.out.println("Enter the name of student : ");
            		String name = sc.next();
            		System.out.println("Enter the class of student : ");
            		String cls = sc.next();
            		BasicDBObject document = new BasicDBObject();
        	        document.append("Rollno", rol);
        	        document.append("Name", name);
        	        document.append("Class", cls);
        	        collection.insert(document);
        	        System.out.println("Document inserted successfully");
            	}
            	else if(opt == 2)
            	{
            		System.out.println("\nEnties in Students collection :");
                    DBCursor cur = collection.find();
                    while(cur.hasNext())
                    {
                    	System.out.println(cur.next());
                    }
            	}
            	else if(opt == 3)
            	{
            		System.out.println("Enter the roll no of student : ");
            		int rol = sc.nextInt();
            		BasicDBObject document = new BasicDBObject();
        	        document.append("Rollno", rol);
            		DBCursor cur = collection.find(document);
            		System.out.println("\nEntry Details : ");
            		System.out.println(cur.next());
            		System.out.println("\nEnter the new name of student : ");
            		String name = sc.next();
            		BasicDBObject docu = new BasicDBObject("$set", new BasicDBObject().append("Name", name));
            		collection.update(document, docu);
        	        System.out.println("Document updated successfully");
            	}
            	else if(opt == 4)
            	{
            		System.out.println("Enter the roll no of student : ");
            		int rol = sc.nextInt();
            		BasicDBObject document = new BasicDBObject();
        	        document.append("Rollno", rol);
            		DBCursor cur = collection.find(document);
            		System.out.println("\nEntry Details : ");
            		System.out.println(cur.next());
            		collection.remove(document);
            		System.out.println("Document deleted successfully");
            	}
            	else
            	{
            		System.out.println("THANKYOU");
            		break;
            	}
            	System.out.println("\n");
            }
            mongoClient.close();
            sc.close();
             
        } catch (Exception ex) {
            ex.printStackTrace();
        }
         
    }
}

