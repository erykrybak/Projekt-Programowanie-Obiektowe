cmake_minimum_required(VERSION 3.10)

project(HotelSystem)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(hotel_app 
    main.cpp 
    bill.cpp 
    guest.cpp 
    hotel_receptionist.cpp 
    hotel_system.cpp 
    reservation.cpp 
    room.cpp
)
