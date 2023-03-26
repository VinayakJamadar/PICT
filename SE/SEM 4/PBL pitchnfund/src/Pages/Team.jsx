import React from "react";
import teamData from "./Teamdata";
import Teamcard from "./Teamcard";

function Team() {

    return (
        <>
            <h2 id="team-heading">The Team</h2>
            <section id="team">
                {teamData ? teamData.map((element, key) => <Teamcard key={key} name={element.name} role={element.role} git={element.git} linkedin={element.linkedin} email={element.email} image={element.image}/>): <></>}
            </section>
        </>
    );
}

export default Team;