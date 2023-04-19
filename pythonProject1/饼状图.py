import matplotlib.pyplot as plt
import numpy as np
import pandas as pd
df=pd.read_csv("./bmi_clear_addcategory.csv")                   #读取文件
ax=df.groupby("BMI_Type").size().sort_values(ascending=False)   #通过BMI的类别进行分类整合并排序
arr=np.array(ax.to_list())                                      #将上一句整合的数据整合为数组
labels=np.array(ax.index.to_list())                             #将第5句整合的数据的分类条件整合为数组
plt.pie(arr,labels=labels,autopct='%0.2f')                      #生成饼状图
plt.show()                                                      #展示图片