/*
=====================================================================
FACTORY PATTERNS – QUICK REVISION NOTES (C++)
=====================================================================

BIG IDEA:
---------
All factory patterns deal with OBJECT CREATION.
Difference is HOW creation is decided and HOW MANY products are created.

---------------------------------------------------------------------
1) SIMPLE FACTORY (Not a GoF Pattern)
---------------------------------------------------------------------

What it is:
- One factory class
- Uses if / else or switch to create objects
- Client asks factory for object by type

Characteristics:
- Centralized creation logic
- Easy to understand
- Violates Open–Closed Principle (OCP)

Example idea:
- ShapeFactory.create("circle")

When to use:
- Small projects
- Quick prototyping
- Competitive programming

Limitations:
- Every new type requires modifying factory
- Not scalable

---------------------------------------------------------------------
2) FACTORY METHOD (GoF Pattern)
---------------------------------------------------------------------

What it is:
- Base class defines factory method
- Subclasses decide which object to create
- Uses inheritance for object creation

Characteristics:
- Follows Open–Closed Principle
- Creation logic is polymorphic
- More classes than Simple Factory

Example idea:
- ShapeCreator (base)
- CircleCreator / SquareCreator (subclasses)

When to use:
- Frameworks
- Plugin-based systems
- When subclasses should control creation

---------------------------------------------------------------------
3) ABSTRACT FACTORY (GoF Pattern)
---------------------------------------------------------------------

What it is:
- Factory of factories
- Creates FAMILIES of related objects
- Ensures compatibility between objects

Characteristics:
- Follows OCP and SRP
- High extensibility
- Higher complexity

Example idea:
- GUIFactory
  - createButton()
  - createCheckbox()
- WinFactory / MacFactory

When to use:
- Cross-platform systems
- UI toolkits
- Database drivers
- Large scalable systems

---------------------------------------------------------------------
COMPARISON SUMMARY:
---------------------------------------------------------------------

Simple Factory:
- if / else based
- creates single product
- low complexity

Factory Method:
- inheritance based
- creates single product
- medium complexity

Abstract Factory:
- composition based
- creates product families
- high complexity

---------------------------------------------------------------------
INTERVIEW MEMORY TRICK:
---------------------------------------------------------------------

Simple Factory     → condition (if / switch)
Factory Method    → inheritance
Abstract Factory  → families of objects

---------------------------------------------------------------------
ONE-LINE INTERVIEW ANSWER:
---------------------------------------------------------------------

Simple Factory centralizes creation,
Factory Method delegates creation to subclasses,
Abstract Factory creates families of related objects.
=====================================================================
*/
