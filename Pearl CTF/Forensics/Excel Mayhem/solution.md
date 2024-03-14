# Excel Mayhem 
## prompt - This excel sheet is troubling me a lot !! help me find the flag . Enclose the flag in pearl{}

By close visual inspection, we observe that the AE Column is missing.

When we try to edit the file, we would discover that the file is password protection.

There are many ways and workarounds to solve this problem, i'm providing one...

### Youtube link - https://youtu.be/z8IfgrjNqgg?si=ujOFq_UNm0RgFuED

Explaination in brief:

- Change the extension of the file from xlsx to zip

- Go to xl -> worksheets -> sheet1.xml 

- Find sheet protection algorithm tag and delete the whole tag

- Rename the extension back to xlsx and open the file normally, you would find the password protection is removed.

- Unhide the hidden column and get the flag

### Flag - pearl{h3ll_0f_4n_3xc3l} 

