# advanced-computer-science-studies
Individually and group work for this course, check Project part for group work of "Project Report".

## Lab 1
How to compile the code and run it

```
gcc -Wall input.c -o input
```
```
./input
```
 
## Project
The final submit consists of these part
* [weather-station-final.py](https://github.com/YolandaDuan/advanced-computer-science-studies/blob/master/project/weather-station-final.py) - Code
* [README.me](https://github.com/YolandaDuan/advanced-computer-science-studies/blob/master/README.md) - Instructions on how to run the code
* [Project_Report_Group_11.pdf](https://github.com/YolandaDuan/advanced-computer-science-studies/blob/master/project/Project_Report_Group_11.pdf) - Report for our project Weather Station

### Prerequisty 
1. For running the code properly, you need Python 2. In our project, we have Python 2.7.13. Use this command line to check which version you have
    ```
    python --version
    ```
2. A Raspberry Pi 3 model B single-board computer
3. A Sense HAT add-on board
4. Download app "pushover notification" to your mobile device
5. Create a firebase project

### Installation
These python libraries need be installed properlly using pip:
```
pip install SenseHat time datetime httplib urllib firebase
```

### Running the code
```
python weather-station-final.py
```
