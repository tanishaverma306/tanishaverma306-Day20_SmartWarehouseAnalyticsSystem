Warehouse Management System (C Program)
This project is a menu-driven Warehouse Management System written in C.
It manages up to 20 products using arrays (no structs) and performs complete stock analysis, including a 3×3 rack matrix.
 Features
 1. Add Product
Stores Product ID, Quantity, and Price
Validates:
No duplicate Product ID
Quantity & Price must be positive
 2. Search Product
Search by Product ID
Displays full details or “Not Found”
 3. Update Quantity
Increase or decrease stock
Prevents negative quantity
 4. Rack Report (3×3 Matrix)
Finds maximum stock & its (row, column)
Finds minimum stock & its (row, column)
Calculates total items in racks
 5. Stock Value Report
Calculates: StockValue = Quantity × Price
Shows:
Stock value of each product
Highest & lowest stock value
Total warehouse value
6. Display All Products
Format:
ID   Quantity   Price   StockValue
How It Works
Uses arrays: ProductID[20], Quantity[20], Price[20]
Uses a 3×3 integer matrix for rack storage
Fully menu-driven
Implemented using functions only
