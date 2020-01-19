void allPermutationRecursive(QStringList restData, QStringList resultData){

    if(restData.isEmpty())
    {
        qDebug()<<"result:"<<resultData;
        return;
    }

    for(int i=0; i<restData.length(); i++){
        // 从剩余的列表中，选择一个，加入结果集
        QStringList newResultData = resultData;
        newResultData.append(restData[i]);

        //将已加入结果集的数据从剩余列表中移除
        QStringList newRestData = restData;
        newRestData.removeAt(i);

        //递归调用，用剩余的列表继续生成排列
        allPermutationRecursive(newRestData, newResultData);
    }
}

void allPermutationIteration(QStringList list){
    QList<QStringList> result, tmp;

    result<<QStringList(list[0]);

    //选择一个数据，加入到每一个结果集的各个位置，生成新的结果集，直到选择到列表的最后一个数据
    for(int j=1; j<list.count(); j++){
        for(int k=0; k<result.count(); k++){
            for(int m=0; m<result[k].count()+1; m++){
                QStringList aa = result[k];
                aa.insert(m, list[j]);
                tmp<<aa;
            }
        }
        result = tmp;
        tmp.clear();
    }
    for(int i= 0; i < result.count(); i++){
        qDebug()<<result[i];
    }
}

void allPermutationWithRepeatRecursive(QStringList list, QStringList result){
    if(list.count() == result.count()){
        qDebug()<<result;
        return;
    }
    for(int i=0; i<list.count(); i++){
        QStringList resultCopy = result;
        resultCopy<<list[i];
        allPermutationWithRepeatRecursive(list, resultCopy);
    }
}

void allPermutationWithRepeatIteration(QStringList list){
    QList<QStringList> result, resultTmp;

    if(list.count() == 0)
        return;

    for(int i=0; i<list.count(); i++){
        result<<QStringList(list[i]);
    }
    for(int i=1; i<list.count(); i++){
        for(int j=0; j<list.count(); j++){
            for(int k = 0; k<result.count(); k++){
                QStringList tmp = result[k];
                tmp.append(list[j]);
                resultTmp.append(tmp);
            }
        }
        result = resultTmp;
        resultTmp.clear();
    }
    for(int i= 0; i < result.count(); i++){
        qDebug()<<result[i];
    }
}

void combineRecursive(QStringList result,  QStringList list, int m){
    if(result.count() == m){
        qDebug()<<result;
        return;
    }

    for(int i = 0; i<list.count(); i++){
        QStringList resultCopy = result;
        resultCopy.append(list[i]);
        QStringList listCopy = list.mid(i+1);
        combineRecursive(resultCopy, listCopy, m);
    }
}

void combineIteration(QStringList list, int m){
    if(list.count() == 0 || m > list.count() || m <= 0)
        return;

    QList<int> tmp;
    for(int i=0; i<m; i++){
        tmp<<i;
    }
    while(true){
        int index = m-1;
        for(;tmp[index]<list.count();){
            QStringList result;
            for(int i=0; i<m; i++){
                result<<list[tmp[i]];
            }
            qDebug()<<result;
            tmp[index]+=1;
        }
        while(index > 0 && tmp[index-1]+1+m-index >= list.count()){
            index--;
        }
        if(index<=0){
            break;
        }else{
            tmp[index-1]+=1;
            for(int i=index; i<m; i++){
                tmp[i]=tmp[i-1]+1;

            }
        }
    }
}


void algorithm(){
    QStringList list;
    for(int i=0; i<3; i++){
        list<<QString::number(i+1);
    }

    qDebug()<<QDateTime::currentDateTime();
    allPermutationRecursive(list, QStringList());

    qDebug()<<QDateTime::currentDateTime();
    allPermutationIteration(list);

    qDebug()<<QDateTime::currentDateTime();
    allPermutationWithRepeatRecursive(list, QStringList());

    qDebug()<<QDateTime::currentDateTime();
    allPermutationWithRepeatIteration(list);

    qDebug()<<QDateTime::currentDateTime();
    combineRecursive(QStringList(), list, 3);

    qDebug()<<QDateTime::currentDateTime();
    combineIteration(list, 3);

    qDebug()<<QDateTime::currentDateTime();
}