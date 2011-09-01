/*
  File: photo.h
  di Maggiolo Giorgio (610338)
  Email: gimaggio@studenti.math.unipd.it
  Progetto: Legami, un progetto per Prog. Ogg.
*/

#include "account.h"
#include "error.h"
#include "photo.h"
#include "username.h"

#include <QFileInfo>

photo::photo(QString type, QString name, QString pathimg, const account& ouwner) throw(error){
    if(!(type==QString("profile"))||!(type==QString("otherphoto"))){
        throw error(Photography, "Invalid photo type");
    }
    _ouwner=const_cast<account*>(&ouwner);
    _type=type;
    _name=name;
    _filephoto= new QFile(pathimg);
    if(!_filephoto->open(QIODevice::ReadOnly)){
        throw error(Photography, "Cannot open photo file");
    }
    QFileInfo fileinfo(*_filephoto);
    QString nameimg=fileinfo.fileName();
    QString pathdir(QString("./photos/")+_ouwner->user()->user());
    QFileInfo selfdir(pathdir);
    if(!(fileinfo.absolutePath()==selfdir.absolutePath())){
        if(!(_filephoto->copy(pathdir+nameimg))){
            throw error(Photography, "Image with the same name exists");
        }
        delete _filephoto;
        _filephoto= new QFile(pathdir+nameimg);
    }
    _filepath=pathdir+nameimg;
    _filephoto->close();
}

photo::~photo(){
    delete _filephoto;
}

QString photo::type() const{
    return _type;
}

QFile* photo::filephoto() const{
    return _filephoto;
}

QString photo::descr() const{
    return _descr;
}

void photo::changeImage(QString newimagepath) throw (error){
    QFile* phototemp= new QFile(newimagepath);
    QFileInfo fileinfo(*phototemp);
    QString nameimg= fileinfo.fileName();
    QString pathdir(QString("./photos/")+_ouwner->user()->user());
    QFileInfo selfdir(pathdir);
    if(!(fileinfo.absolutePath()==selfdir.absolutePath())){
        if(!(phototemp->copy(pathdir+nameimg))){
            throw error(Photography, "Image with the same name exists");
        }
    }
    delete _filephoto;
    _filepath=pathdir+nameimg;
    _filephoto= new QFile(pathdir+nameimg);
    phototemp->close();
    delete phototemp;
}

void photo::setType(QString type) throw(error){
    if(!(type==QString("profile"))||!(type==QString("othphoto"))){
        throw error(Photography, "Invalid photo type");
    }
    _type=type;
}

void photo::setDescr(QString descr){
    _descr=descr;
}

QString photo::name() const{
    return _name;
}

QString photo::filepath() const{
    return _filepath;
}
