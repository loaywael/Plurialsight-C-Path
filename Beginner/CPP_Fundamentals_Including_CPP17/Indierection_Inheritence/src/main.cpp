#include <iostream>
#include "../include/utils.hpp"
#include <memory>


void print(std::string const& msg, bool endline=true) {
    std::cout << msg << "\t";
    if (endline) {
        std::cout << std::endl;
    }
}


void printWork1(Person obj) {
    print("inside printWork1 call by val");
    obj.do_work();
    }

void printWork2(const Person& obj) {
    print("inside printWork2 call by reference");
    obj.do_work();
}

int main(int argc, char** argv) {

    print("Welcome in Main");

    // -----------------------------------
    // ------ Normal Inistantiation ------
    // -----------------------------------

    
    Person pr("Ahmed", 19);
    pr.printName();
    pr.do_work();
    // --------------------
    Developer dvr("Raed", 19, "Developer", "C++ Inheritance");
    dvr.printName();
    dvr.do_work();
    // --------------------
    Teacher tch("Baraa", 19, "Teacher", "Programming");
    tch.printName();
    tch.do_work();
    print("-------------------------\n");


    // -----------------------------------
    // ------- Normal Type Casting -------
    // -----------------------------------
    {
        print("successfully casted from Derived to Base");
        Person obj1 = Person();
        Developer obj2 = Developer();
        Person obj3 = static_cast<Person>(obj2);
        print("But Failed to C++/C style castes from Base to Derive");
        // Person obj4 = static_cast<Developer>(obj1);
        // Person obj4 = (Developer) obj1;
    }


    // ----------------------------------
    // ----- Reference Type Casting -----
    // ----------------------------------
    {   // straight forward casting Base to Derived then Derived to Base
        print("Casting By References");
        Person srcObj1 = Person(pr);
        Person& refObj1 = srcObj1;
        Developer srcObj2 = Developer(dvr);
        Developer& refObj2 = srcObj2;
        print("Successfully Casted from Derived to Base allowing polymorphism");
        // same as saying Base castedObj = (Base) derivedObj
        Person& obj3 = static_cast<Person&>(refObj2);
        obj3.printName();
        obj3.do_work();
        obj3.setName("NewName");
        obj3.setTitle("NewTitle");
        obj3.printName();
        obj3.do_work();
        
        print("\nCasting from Base to Derive");
        /* 
        It was promoted to Derived but with copied state from the initialization of the Base constructor
        this is dangerous it allowed converting Base to Derive which have extra capabilities 
        but it still thinks it is a Base object hence it uses the Base do_work not the Derived one
        */
        Developer& obj4 = static_cast<Developer&>(refObj1);
        // Developer& dstObj2 = (Developer&) refObj1;
        obj4.printName();
        obj4.stateYourJob();
        obj4.do_work();
        obj4.setName("007");
        obj4.setTitle("Client");
        obj4.printName();
        obj4.stateYourJob();
        obj4.do_work();

    }

    {   // tricky casting Base to Derived then Derived to Base
        print("Tricky Casting By References");
        Person srcObj1 = Developer(dvr);
        Person& refObj1 = srcObj1;
        
        print("casting from Derived to Base");
        // dangerous conversion the same result as before
        Developer& obj3 = static_cast<Developer&>(refObj1);
        obj3.printName();
        obj3.stateYourJob();
        obj3.do_work();
    }

    // -----------------------------------
    // --------- Pointer Casting ---------
    // -----------------------------------
    print("Casting by Pointers");
    print("Casting unique/shared ptr from Base to Derived is blocked for safety");
    print("This is gaurding from any bad conversion C-style cast may allow");
    // std::shared_ptr<Person> norm_pr_ptr = std::make_shared<Developer>();
    // std::shared_ptr<Developer> ptr = (std::shared_ptr<Developer>) norm_pr_ptr;
    // std::shared_ptr<Developer> ptr = static_cast<std::shared_ptr<Developer>>(norm_pr_ptr);
    // -----------   instead use C-style pointer   ------------
    print("Casting C-style ptr from Base to Derived is possible");
    print("going from Base to Derive is dangerous however C-syle cast allow it");
    {
        Person* norm_pr_ptr = new Developer("Eren", 25, "Legend", "Phishing");
        Developer* danger_ptr = static_cast<Developer*>(norm_pr_ptr);
        danger_ptr->printName();
        danger_ptr->stateYourJob();
        danger_ptr->do_work();
        delete norm_pr_ptr; 
        norm_pr_ptr=nullptr;
    }

    {   // even after casting the pointer still acts like a Base not derived
        Person* danger_ptr = new Person("Eren", 25);
        Developer* most_dangerous_ptr = static_cast<Developer*>(danger_ptr);
        danger_ptr->printName();
        // danger_ptr->stateYourJob();
        danger_ptr->do_work();
        delete danger_ptr; 
        danger_ptr=nullptr;
    }


    // -----------------------------------
    // --------   Polymorphism   --------
    // -----------------------------------

    print("Applying Polymorphism");
    print("-------------------------");
    {
        auto pr_ptr = std::make_unique<Person>(pr);
        pr_ptr->printName();
        pr_ptr->do_work();
    }
    
    {
        auto prDvr_ptr(std::make_unique<Developer>(dvr));
        prDvr_ptr->printName();
        prDvr_ptr->stateYourJob();
        prDvr_ptr->do_work();
    }

    {   // copying blocks polymorphism so this prints nothing to do
        std::unique_ptr<Person> prDvr_ptr(std::make_unique<Developer>(dvr));
        prDvr_ptr->printName();
        // prDvr_ptr->stateYourJob();   // can't be accessed since it is Person pointer
        prDvr_ptr->do_work();
    }
    
    {
        std::shared_ptr<Developer> norm_pr_ptr = std::make_shared<Developer>();
        std::shared_ptr<Person> ptr = static_cast<std::shared_ptr<Person>>(norm_pr_ptr);
        print("Casting Developer to Person using shared_ptr was successfull but not unique_ptr");
    }
    

    {
        std::unique_ptr<Person> prTch_ptr = std::make_unique<Teacher>("Neo", 33, "Master", "Hacking");
        prTch_ptr->printName();
        prTch_ptr->do_work();

    }

    
    print("\nCall by Val vs Call by Ref polymorphism");
    // allow polymorphism using reference/C-pointer/Smart-pointer
    Person& obj = dvr;
    obj.do_work();
    Person* prPtr = &dvr;
    prPtr->do_work();
    std::unique_ptr<Person> uniq_prPtr = std::make_unique<Developer>(dvr);
    uniq_prPtr->do_work();

    // blocks polymorphism due to call by value
    printWork1(dvr);
    printWork1(obj);
    // ------------
    printWork2(dvr);
    printWork2(obj);
    printWork2(*prPtr);
    printWork2(*uniq_prPtr);

    print("-------------------------\n");
    print("finished\n-------------------------");
    return 0;
}