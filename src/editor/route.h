// This file is part of Dust Rallycross (DustRAC).
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

#ifndef ROUTE_H
#define ROUTE_H

#include <QVector>

class TrackTile;

//! Route is used to define the race route as a sequence
//! of TrackTiles.
class Route
{
public:

    //! Clear the current route.
    void clear();

    //! Push new tile to the route and return its index.
    int push(TrackTile * tile);

    //! Return length of the current route.
    unsigned int length() const;

private:

    QVector<TrackTile *> m_route;
};

#endif // ROUTE_H