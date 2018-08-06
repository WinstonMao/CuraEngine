//Copyright (c) 2018 Ultimaker B.V.
//CuraEngine is released under the terms of the AGPLv3 or higher.

#ifndef LAYERINDEX_H
#define LAYERINDEX_H

namespace cura
{

/*
 * Struct behaving like a layer number.
 *
 * This is a facade. It behaves exactly like an integer but is used to indicate
 * that it is a layer number.
 */
struct LayerIndex
{
    /*
     * Casts an integer to a LayerIndex instance.
     */
    LayerIndex(int value) : value(value) {};

    /*
     * Casts the LayerIndex instance to an integer.
     */
    operator int() const
    {
        return value;
    }

    LayerIndex operator +(const LayerIndex& other) const
    {
        return LayerIndex(value + other.value);
    }

    LayerIndex operator -(const LayerIndex& other) const
    {
        return LayerIndex(value - other.value);
    }

    LayerIndex& operator +=(const LayerIndex& other)
    {
        value += other.value;
        return *this;
    }

    LayerIndex& operator -=(const LayerIndex& other)
    {
        value -= other.value;
        return *this;
    }

    /*
     * The actual layer index.
     *
     * Note that this could be negative for raft layers.
     */
    int value = 0;
};

}

#endif //LAYERINDEX_H