# Kgaurav
Battery Management system
UNIX: C and C++


Balancing or equalizing is the process of modifying the level of charge in cells on a cell-by-cell basis.
There are two basic approaches to balancing:
1. Passive balancing drains charge from cells having too much charge and dissipates drained energy as heat.
2. Active balancing moves charge from “high cells” to “low cells,” attempting to conserve energy in the battery pack.

1.	Balancing circuitry includes Bleed resistor and the Transistor which selectively switches the bypass branch ON/OFF according to the relative SOC of the battery cells (Transistor act as switches). The resistor diverts part of the charging current thereby slowing down the rate of charge of the cell they are connected to allowing the cell below to catch up.  
2.	SOC level may be initially low and possibly some few percentage differences from one another. They slowly approach each other as they increase until their values are close enough in charging can proceed without balancing. 
Here are several assumptions of the battery cell model :
(a)	The parameters of the model are deduced from discharging characteristics. Here, I have consider linear discharging rate for each cell.
(b)	The internal resistance is supposed to be constant during the discharging cycles and does not vary with the different amplitude of the current.
(c)	The self-discharge of the battery is not represented and the battery has no memory effect.
(d)	The model does not take the temperature into account.


# Resources

http://ww1.microchip.com/downloads/en/AppNotes/00231a.pdf
https://www.mpoweruk.com/bms.htm
https://www.hindawi.com/journals/mpe/2015/168529/
https://en.wikipedia.org/wiki/Battery_balancing

# Contributing

Please read the contribution guidelines before starting work on a pull request.


# Summary of the guidelines:

One pull request per issue;

Choose the right base branch;

Include tests and documentation;

Follow the coding style guide.
