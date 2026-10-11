# Campus-Resource-Reservation-System-Project1
Campus Resource Reservation System Project 1

## Project Description

This C++ application manages campus resources, reservations, and waiting lists while demonstrating object-oriented programming, searching, sorting, reporting, and data structures. 

## Team Members

- Trenton Maxime (x4mt and tm5x)
- Alison Rojo Hernandez
- Steven Aguilar

Individual responsibilities and contributions are documented in the
separate Group Contribution Report.

## Project Files

CancellationHistory.h
Reservation.h
ReservationList.h
ReservationManager.h
Resource.h
WaitingList.h

CancellationHistory.cpp
Reservation.cpp
ReservationList.cpp
ReservationManager.cpp
Resource.cpp
WaitingList.cpp
main.cpp

## Features
The program allows users to view campus resources, create, cancel, search, and sort reservations, view cancellation history, undo cancellations, and manage student waiting lists. It also supports system reports for active reservations, resource utilization, and waiting-list statistics. The project uses a linked list for active reservations, a FIFO queue for waiting lists, and a LIFO stack for cancellation history.

## Compile and Run

From the project root on the UNT CELL system or Linux: g++ -std=c++17 -Wall -Wextra src/*.cpp -o reservation_app
./reservation_app

Choose an option from the numbered menu. The program will read the text files if ran from the project root.

