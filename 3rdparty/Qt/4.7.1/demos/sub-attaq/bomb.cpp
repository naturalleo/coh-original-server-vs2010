/****************************************************************************
**
** Copyright (C) 2010 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the QtCore module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial Usage
** Licensees holding valid Qt Commercial licenses may use this file in
** accordance with the Qt Commercial License Agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Nokia.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain additional
** rights.  These rights are described in the Nokia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3.0 as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU General Public License version 3.0 requirements will be
** met: http://www.gnu.org/copyleft/gpl.html.
**
** If you have questions regarding the use of this file, please contact
** Nokia at qt-info@nokia.com.
** $QT_END_LICENSE$
**
****************************************************************************/

//Own
#include "bomb.h"
#include "submarine.h"
#include "pixmapitem.h"
#include "animationmanager.h"
#include "qanimationstate.h"

//Qt
#include <QtCore/QSequentialAnimationGroup>
#include <QtCore/QPropertyAnimation>
#include <QtCore/QStateMachine>
#include <QtCore/QFinalState>

Bomb::Bomb() : PixmapItem(QString("bomb"), GraphicsScene::Big)
{
    setZValue(2);
}

void Bomb::launch(Bomb::Direction direction)
{
    QSequentialAnimationGroup *launchAnimation = new QSequentialAnimationGroup;
    AnimationManager::self()->registerAnimation(launchAnimation);
    qreal delta = direction == Right ? 20 : - 20;
    QPropertyAnimation *anim = new QPropertyAnimation(this, "pos");
    anim->setEndValue(QPointF(x() + delta,y() - 20));
    anim->setDuration(150);
    launchAnimation->addAnimation(anim);
    anim = new QPropertyAnimation(this, "pos");
    anim->setEndValue(QPointF(x() + delta*2, y() ));
    anim->setDuration(150);
    launchAnimation->addAnimation(anim);
    anim = new QPropertyAnimation(this, "pos");
    anim->setEndValue(QPointF(x() + delta*2,scene()->height()));
    anim->setDuration(y()/2*60);
    launchAnimation->addAnimation(anim);
    connect(anim,SIGNAL(valueChanged(QVariant)),this,SLOT(onAnimationLaunchValueChanged(QVariant)));
    connect(this, SIGNAL(bombExploded()), launchAnimation, SLOT(stop()));
    //We setup the state machine of the bomb
    QStateMachine *machine = new QStateMachine(this);

    //This state is when the launch animation is playing
    QAnimationState *launched = new QAnimationState(machine);
    launched->setAnimation(launchAnimation);

    //End
    QFinalState *final = new QFinalState(machine);

    machine->setInitialState(launched);

    //### Add a nice animation when the bomb is destroyed
    launched->addTransition(this, SIGNAL(bombExploded()),final);

    //If the animation is finished, then we move to the final state
    launched->addTransition(launched, SIGNAL(animationFinished()), final);

    //The machine has finished to be executed, then the boat is dead
    connect(machine,SIGNAL(finished()),this, SIGNAL(bombExecutionFinished()));

    machine->start();

}

void Bomb::onAnimationLaunchValueChanged(const QVariant &)
{
    foreach (QGraphicsItem * item , collidingItems(Qt::IntersectsItemBoundingRect)) {
        if (item->type() == SubMarine::Type) {
            SubMarine *s = static_cast<SubMarine *>(item);
            destroy();
            s->destroy();
        }
    }
}

void Bomb::destroy()
{
    emit bombExploded();
}
