#ifndef KEYBOARDMANAGER_H
#define KEYBOARDMANAGER_H


#include <QMap>
#include <QKeyEvent>
#include <QDebug>

namespace KeyboardManager
{

    extern QMap<int,bool> keys;

    inline static void KeyPress(QKeyEvent *e)
    {
        if(e->isAutoRepeat())
            return;
        KeyboardManager::keys[e->key()] = true;
        qDebug() << "Key press" << e->key() << " " << "true" << " " << KeyboardManager::keys[e->key()];
    }

    inline static void KeyRelease(QKeyEvent *e)
    {
        if(e->isAutoRepeat())
            return;
        KeyboardManager::keys[e->key()] = false;
        qDebug() << "Key release " << e->key() << " " << "false" << " " << KeyboardManager::keys[e->key()];
    }

    inline static bool IsKeyDown(int key)
    {

        if(! KeyboardManager::keys.contains(key))
        {
            qDebug() << "BREAK";
           // KeyboardManager::keys[key] = false;
        }
        //qDebug() << "Key check " << key << " " << KeyboardManager::keys[key];
        return KeyboardManager::keys[key];
    }

}

#endif // KEYBOARDMANAGER_H
