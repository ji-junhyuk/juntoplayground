package jpabook.jpashop;

import javax.persistence.DiscriminatorValue;
import javax.persistence.Entity;

@Entity
@DiscriminatorValue("A")
public class Album {

    private String artist;
    private String etc;
}
