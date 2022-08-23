import React from 'react';
import { PieChart, Pie } from 'recharts';


const Graph = (props) => {

    const data = [
        { name: "investor", value: props.equity, fill: 'rgb(255, 0, 0)' },
        { name: "entrepreneur", value: 100 - props.equity, fill: 'rgba(173,210,230,1)' }
    ];

    return (
        <PieChart width={100} height={100}>
            <Pie 
            data={data} 
            dataKey="value" 
            outerRadius={50} 
            innerRadius={30}
            fill = "white"
            />
        </PieChart>
    );
}

export default Graph;