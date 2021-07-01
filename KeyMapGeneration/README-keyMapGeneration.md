# How to use keyMapGeneration

1. Input your desired keymap to a CSV file. The first column is the **key name**, which will not effect the result, name it as you will. The second column is the **AT scan code**. The third is the **Bluetooth code** for the Bluetooth keyboard library. If the key (without modifiers) is an ASCII charcter, use the **ASCII code** as the Bluetooth code. If it is not, use **\[HID code + 136(decimal)\]**.
2. Change the input filename in the Python script to match our CSV file.
3. Run the Python Script, the script will generate an array in a text file. This array uses the AT scan code as the index, Bluetooth code as the element.
4. Copy the array into **keyMaps.h**, and replace the corresponding array in that file.

## Please note that you need two key maps, one for non-extended keys, and another for extended keys.

Examples of the input CSV file and output text file are provided, with both extended and non-extended keys. These are the key maps that I use on my BTC-5339-R0.
