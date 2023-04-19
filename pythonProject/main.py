import matplotlib.pyplot as plt
import pandas as pd
df=pd.read_csv("./bmi_clear_addcategory.csv")                       #读取文件
def isMale(a):                                                      #判断是否男性的函数
    return a=='Male'
arr1 = df.loc[df['Sex'].apply(isMale)]                              #将文件中的男性BMI独立成一个数组
def isFemale(a):                                                    #判断是否女性的函数
    return a=='Female'
arr2 = df.loc[df['Sex'].apply(isFemale)]                            #将文件中的女性BMI独立成一个数组
plt.boxplot([arr1['BMI'],arr2['BMI']],labels=['Male','Female'])     #生成箱型图
plt.show()                                                          #展示图片