/*
================ POINTER ===============

    - Pointer is a variable which contains address of another
    variable. 
    
    - Pointer is Declared using * symbol.

    -Pointer Content is Consider address of the variable of type 
    same as the type of the pointer ( *int = int , *char = char ...etc).

    -Pointer always store base address 
    
    -Size of Pointer is not dependent one its data type , 
    it is always 8 Byte.


    ================ OBJECT POINTER ==================

    for example : int a = 7;
    Pointer     : int *p = &a;
    value : *p
    addres : p

    class A {}
    create Object    : A c1;
    Object se Access : c1.member.. methode ..(public)
    Object Pointer   : A *p = &c1;
    Access Object using Pointer : *p.show(); wrong

    class mai kisi object ke behavior ko . se call karte hai 
    but . operator ki scope jyada hoti ham pehle dereferencing karna chahte
    hai

    so.. : (*p).show(); // pehle deference 
    
    but ye thoda shi tareeka nhi hai 
    p->show(); yhi use karna hai


*/