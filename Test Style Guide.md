# Style Guide

## Program and Hardware Name Standards

* XinaBox - the product line
* xChips - the chips themselves
* xSystem - a single system of connected xChips

## Lab Information

Lab Titles: "Lab X: Doing Something"

At the beginning of each lab, include a bill of materials (BOM).
Computer with Arduino IDE is assumed, don't put it in the list
Not a 'capitalized' list.
When it's made, we can have each item in the BOM link to an info page about each chip.

To perform this lab you will need:
1. IP01 xChip- USB module
2. CW01 xChip- WiFi module and processor 
3. OD01 xChip- OLED display module
4. 2 connector pieces

(Include a horizontal line after the BOM)
*** 

## General Formatting
> Pro-Tip: Put extra information, hints, colloquial explanations, tips in quote boxes

xChips instead of x-Chips, X-Chips, X-CHIPS, XCHIPS, XChips

xSystem when referring to the whole system of stuff. "The xSystem is designed to ...."

Capitalize All Important Words in a Title or Header, including numbered lists with a paragraph below the number.

## Code Formatting

When referring to code keywords (variable types, function names, etc) in tutorial text, use `inline code` style by enclosing the keyword in the \` backtick character. 

> Pro-tip: Enclose code blocks in \`\`\` and include "Arduino" for code syntax highlighting


```
```Arduino
// Sample Code Block
void setup() {
  Serial.begin();
}```
```


Produces :


```Arduino
// Sample Code Block
void setup() {
  Serial.begin();
}
```

