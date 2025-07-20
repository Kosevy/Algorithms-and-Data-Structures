# SkyBros
Final project developed during the Algorithms and Data Structures course 2025-01 using C++

Purpose and Scope:
This document provides a comprehensive overview of a travel management system, a C++ console application that enables users to search, book, and manage flights along with integrated travel services. The system serves as a complete travel booking platform with sophisticated data structures powering flight search, reservation management, hotel booking, car rental, and airport transfer services.

This overview covers the system's architecture, core components, and integration patterns. For detailed information about specific subsystems, see System Architecture for architectural details, Flight Operations for flight management specifics, Reservation Management System for booking details, and Additional Travel Services for hotel, car rental, and transfer services.

System Architecture
The SkyBros-TF system follows a layered architecture with a central orchestrator managing interactions between specialized subsystems. The application is built around a menu-driven interface that provides access to flight operations, reservation management, and additional travel services.

High-Level System Architecture:
<img width="1707" height="316" alt="image" src="https://github.com/user-attachments/assets/89c21819-4d98-42c4-8134-5efa9d43eec8" />

Core Components and Code Entity Mapping:
The system consists of several interconnected components, each implemented as specialized classes with distinct responsibilities. The following diagram maps the natural language system names to their corresponding code entities.

Component-to-Code Entity Mapping:
<img width="1714" height="820" alt="image" src="https://github.com/user-attachments/assets/310546e9-39f0-4fef-9767-fa02b3b49c93" />

Application Flow and User Journey:
The system follows a structured flow from authentication through service selection and booking completion. The main application loop provides access to three primary functional areas: flight operations, reservation management, and additional services.

Main Application Flow:
<img width="811" height="817" alt="image" src="https://github.com/user-attachments/assets/86a20bcb-2400-42c5-8d9c-11533c0bdf9c" />

System Integration Points:
The system demonstrates sophisticated integration between its components, particularly in how additional services interact with the flight reservation system. The integration ensures that hotels can be associated with existing flight reservations, creating a cohesive travel booking experience.

<img width="1120" height="804" alt="image" src="https://github.com/user-attachments/assets/23267814-3e47-479f-b717-44a6a12f37b2" />
