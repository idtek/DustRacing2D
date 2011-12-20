// This file is part of Dust Racing (DustRAC).
// Copyright (C) 2011 Jussi Lind <jussi.lind@iki.fi>
//
// DustRAC is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// DustRAC is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with DustRAC. If not, see <http://www.gnu.org/licenses/>.

#ifndef SCENE_H
#define SCENE_H

#include "car.h"
#include "race.h"

class InputHandler;
class MCCamera;
class MCObject;
class MCSurface;
class MCWorld;
class Track;

//! The game scene.
class Scene
{
public:

    //! Constructor.
    explicit Scene(MCSurface & carSurface);

    //! Destructor.
    ~Scene();

    //! Update physics and objects by the given
    //! time step.
    void updateFrame(InputHandler & handler,
        MCCamera & camera, float timeStep);

    //! Set the active race track.
    void setActiveTrack(Track & activeTrack);

    //! Return the active race track.
    Track & activeTrack() const;

    //! Return the world.
    MCWorld & world() const;

private:

    Track   * m_pActiveTrack;
    MCWorld * m_pWorld;
    Car       m_car;
    Car       m_testCar;
    Race      m_race;
    MCFloat   m_cameraBaseOffset;
};

#endif // SCENE_H
