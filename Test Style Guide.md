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

### Deeper Understanding

Use this title at the end of a lab to include the "Deeper Understanding" section. 

(Include a horizontal line after the BOM)
*** 

## General Formatting
> **Pro-Tip:** Put extra information, hints, colloquial explanations, tips in quote boxes. Add bold style to the beginning "category," e.g. Try-It:, Note:, Pro-tip:, etc.

xChips instead of x-Chips, X-Chips, X-CHIPS, XCHIPS, XChips

xSystem when referring to the whole system of stuff. "The xSystem is designed to ...."

Capitalize All Important Words in a Title or Header, including numbered lists with a paragraph below the number.

## Code Formatting in wiki

When referring to code keywords (variable types, function names, etc) in tutorial text, use `inline code` style by enclosing the keyword in the \` backtick character. 

> **Pro-tip:** Enclose code blocks in \`\`\` and include "Arduino" for code syntax highlighting


```Markdown
    ```Arduino
    // Sample Code Block
    void setup() {
      Serial.begin();
    }
    ```
```


Produces :


```Arduino
// Sample Code Block
void setup() {
  Serial.begin();
}
```

## Troubleshooting File

Problem: I am hungry!

Solution: Eat a snack.

## To link a File
No spaces in file names. Use dashes. Save with file extension. File names are start lowercase.

File extensions should be all lowercase wherever possible.

Linking to any files in a subfolder requires the use of relative paths and takes the form "foldername/file.ext" - note the forward slash (frontslash `/`). Windows default is backslash `\` but it will accept a frontslash.

## Image markdown

It is best practice to include a description of the image in the `[]` portion of the image markdown. This gets translated into image alt-text and helps with search indexing and accessibility for the sight-impaired.

```Markdown
![x-chip test assembly](xinabox-images/first-xchip-test.jpg)
```

> **Pro-tip:** The description/alt-text is rendered in place of the image if the image link is broken or if the user has images disabled on their browser.

# Code Style Guide

include header
///////////////////////////
// This program runs rainbow snakes
// Uses OD01, CW01, IP01 xChips
// Written by E. Bujold
//////////////////////////

#include <xCore.h>  //This library makes the processor usable
#include <xSL01.h>  //This library makes the light sensor usable
#include <xOD01.h>  //This library makes the OLED screen usable

Comment as many lines as isn't redundant *within* the file. Use previous codes for examples.
